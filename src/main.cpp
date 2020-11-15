//#include <iostream>
//#include "dia2.h"
//
//bool myLoadDataFromPdb(
//        const wchar_t    *szFilename,
//        IDiaDataSource  **ppSource,
//        IDiaSession     **ppSession,
//        IDiaSymbol      **ppGlobal)
//{
//    wchar_t wszExt[MAX_PATH];
//
//    HRESULT hr = CoInitialize(NULL);
//
//    // Obtain access to the provider
//
//    hr = CoCreateInstance(__uuidof(DiaSource),
//                          NULL,
//                          CLSCTX_INPROC_SERVER,
//                          __uuidof(IDiaDataSource),
//                          (void **) ppSource);
//
//    if (FAILED(hr)) {
//        wprintf(L"CoCreateInstance failed - HRESULT = %08X\n", hr);
//
//        return false;
//    }
//
//    _wsplitpath_s(szFilename, NULL, 0, NULL, 0, NULL, 0, wszExt, MAX_PATH);
//
//    if (!_wcsicmp(wszExt, L".pdb")) {
//        // Open and prepare a program database (.pdb) file as a debug data source
//
//        hr = (*ppSource)->loadDataFromPdb(szFilename);
//
//        if (FAILED(hr)) {
//            wprintf(L"loadDataFromPdb failed - HRESULT = %08X\n", hr);
//
//            return false;
//        }
//    }
//
//    else {
//        return false;
//    }
//
//    // Open a session for querying symbols
//
//    hr = (*ppSource)->openSession(ppSession);
//
//    if (FAILED(hr)) {
//        wprintf(L"openSession failed - HRESULT = %08X\n", hr);
//
//        return false;
//    }
//
//    // Retrieve a reference to the global scope
//
//    hr = (*ppSession)->get_globalScope(ppGlobal);
//
//    if (hr != S_OK) {
//        wprintf(L"get_globalScope failed\n");
//
//        return false;
//    }
//
//    // Set Machine type for getting correct register names
//
//    return true;
//}
//
//int main() {
//    //wchar_t* path = L"C:\\Users\\kirill.timofeev\\Downloads\\jbrsdk-11_0_8-windows-x64-fastdebug-b1026.tar\\jbrsdk\\bin\\server\\jvm.pdb";
//    wchar_t* path = L"C:\\Desktop\\debug-symbols-playground\\cmake-build-debug\\debug_symbols_playground.pdb";
//
//    IDiaDataSource *g_pDiaDataSource;
//    IDiaSession *g_pDiaSession;
//    IDiaSymbol *g_pGlobalSymbol;
//
//    if (!myLoadDataFromPdb(path, &g_pDiaDataSource, &g_pDiaSession, &g_pGlobalSymbol)) {
//        return -1;
//    }
//
//    IDiaEnumSymbols *pEnumChildren;
//
//    if (!SUCCEEDED(g_pGlobalSymbol->findChildren(SymTagFunction, NULL, nsNone, &pEnumChildren))) {
//        return -1;
//    }
//    LONG count;
//    pEnumChildren->get_Count(&count);
//    std::cerr << "pEnumChildren->get_Count: " << count << std::endl;
//    IDiaSymbol *pSymbol;
//    ULONG celtChildren = 0;
//    while (SUCCEEDED(pEnumChildren->Next(1, &pSymbol, &celtChildren)) && celtChildren == 1) {
//        BSTR bstrName;
//        ULONGLONG va;
//        ULONGLONG len;
//        DWORD rva;
//        DWORD ordinal;
//        DWORD locationType;
//        pSymbol->get_ordinal(&ordinal);
//        pSymbol->get_name(&bstrName);
//        pSymbol->get_virtualAddress(&va);
//        pSymbol->get_length(&len);
//        pSymbol->get_relativeVirtualAddress(&rva);
//        if (pSymbol->get_locationType(&locationType) == S_FALSE){
//            locationType = 0;
//        };
//        std::wstring str(bstrName);
//        //std::wcerr << str ;// << "(, start:" << std::endl;
//        wprintf(L"%s (start: %lld, len: %lld, rva: %lld, ordinal: %lld, locationType: %lld)\n", bstrName, va, len, ordinal, locationType);
//        SysFreeString(bstrName);
//    }
//
//    return 0;
//}
