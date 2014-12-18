#include "helper.h"

#include <AknGlobalNote.h>
#include <apgcli.h>
#include <coemain.h>
#include <apgtask.h>
#include <akndiscreetpopup.h>

#include <QtGui/QFileDialog.h>

#include "QCenRep.h"

//#include <QDebug>


void Helper::CRep4All() const noexcept {
    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus;
    note->ShowNoteL(iStatus,
                    EAknGlobalErrorNote,
                    _L("You have to enable CRepository4all in ROMPatcher +.")
                    );
    User::WaitForRequest(iStatus);
    CleanupStack::PopAndDestroy(note);
}

bool Helper::reset(const QString &sRepo, const QString &qKey) const noexcept {
    if(QCenRep::reset(sRepo, qKey) == -46){
        CRep4All();
        return false;
    }
    return true;
}

void Helper::success() const noexcept {
    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus;
    note->ShowNoteL(iStatus,
                    EAknGlobalConfirmationNote,
                    _L("Success!")
                    );
    User::WaitForRequest(iStatus);
    CleanupStack::PopAndDestroy(note);
}

QString Helper::getiso() const noexcept {
    QString val;
    QCenRep::ReadValStr(TUid::Uid(0x2000fda8), 0x1, &val);
    return val;
}

bool Helper::setiso() const noexcept {
    const QString result = QFileDialog::getOpenFileName(0, "Select a .iso file", "", "*.iso").replace("/","\\");
    if(result.isEmpty()) {
        return false;
    }
    if(QCenRep::ChangeValStr(TUid::Uid(0x2000fda8), 0x1, result) == -46) {
        CRep4All();
        return false;
    }
    return true;
}

void Helper::loadPage(const QString &url) const noexcept {
    TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Wait")), (_L("Loading ...")),KAknsIIDNone, KNullDesC, 0, 0, 0x00000001, 0, NULL));
    TPtrC16 tUrl(reinterpret_cast<const TUint16*>(url.utf16()));
    RApaLsSession appArcSession;
    if(appArcSession.Connect() == KErrNone) {
        CleanupClosePushL<RApaLsSession>(appArcSession);
        TDataType mimeDatatype(_L8("application/x-web-browse"));
        TUid handlerUID;
        appArcSession.AppForDataType(mimeDatatype, handlerUID);
        if (handlerUID.iUid == 0 || handlerUID.iUid == -1) handlerUID = TUid::Uid(0x10008D39);
        _LIT(KBrowserPrefix, "4 " );
        HBufC* buf16 = HBufC::NewLC(tUrl.Length() + KBrowserPrefix.iTypeLength);
        buf16->Des().Copy(KBrowserPrefix);
        buf16->Des().Append(tUrl);
        TApaTaskList taskList(CCoeEnv::Static()->WsSession());
        TApaTask task = taskList.FindApp(handlerUID);
        if (task.Exists()) {
            task.BringToForeground();
            HBufC8* param8 = HBufC8::NewLC(buf16->Length());
            param8->Des().Append(buf16->Des());
            task.SendMessage(TUid::Uid( 0 ), *param8);
            CleanupStack::PopAndDestroy(param8);
        }
        else {
            TThreadId id;
            appArcSession.StartDocument(*buf16, handlerUID, id);
        }
        CleanupStack::PopAndDestroy(buf16);
        CleanupStack::PopAndDestroy(&appArcSession);
    }
}
