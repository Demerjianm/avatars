let component = ReasonReact.statelessComponent("Icon");

let make = (~style=?, ~name, _children) => {
  ...component,
  render: _self =>
    switch (name) {
    | "arrow" =>
      <svg
        className="IconLink-icon"
        ?style
        height="12"
        viewBox="0 0 12 12"
        width="12"
        xmlns="http://www.w3.org/2000/svg">
        <path
          d="m6.67157288 6-4.29289322-4.29289322c-.3905243-.39052429-.3905243-1.02368927 0-1.41421356.39052429-.39052429 1.02368927-.39052429 1.41421356 0l5.70710678 5.70710678-5.70710678 5.7071068c-.39052429.3905243-1.02368927.3905243-1.41421356 0-.3905243-.3905243-.3905243-1.0236893 0-1.4142136z"
          fill="#5a45ff"
        />
      </svg>
    | "randomize" =>
      <svg
        className="IconLink-icon"
        ?style
        height="16"
        viewBox="0 0 16 16"
        width="16"
        xmlns="http://www.w3.org/2000/svg">
        <path
          d="m457.5 1016c-.276142 0-.5-.22386-.5-.5s.223858-.5.5-.5h4.5v4.5c0 .27614-.223858.5-.5.5s-.5-.22386-.5-.5v-2.82637c-2.364947 1.12347-4 3.53397-4 6.32637 0 3.69788 2.867362 6.72604 6.5 6.98242v.01758c.276142 0 .5.22386.5.5s-.223858.5-.5.5c-.056943 0-.111664-.00952-.162656-.02705-4.108263-.33686-7.337344-3.77781-7.337344-7.97295 0-3.01203 1.664575-5.63527 4.123993-7zm13 14c.276142 0 .5.22386.5.5s-.223858.5-.5.5h-4.5v-4.5c0-.27614.223858-.5.5-.5s.5.22386.5.5v2.82637c2.364947-1.12347 4-3.53397 4-6.32637 0-3.69788-2.867362-6.72604-6.5-6.98242v-.01758c-.276142 0-.5-.22386-.5-.5s.223858-.5.5-.5c.056943 0 .111664.00952.162656.02705 4.108263.33686 7.337344 3.77781 7.337344 7.97295 0 3.01203-1.664575 5.63527-4.123993 7z"
          fill="#5a45ff"
          transform="translate(-456 -1015)"
        />
      </svg>
    | "wordmark" =>
      <svg
        viewBox="0 0 708 168" width="120" xmlns="http://www.w3.org/2000/svg">
        <g fill="none" fillRule="evenodd">
          <path
            d="m89.805073 3.08327199 54 30.30275341c7.53527 4.2285079 12.194927 12.1593293 12.194927 20.7559885v59.7159721c0 8.596659-4.659657 16.527481-12.194927 20.755989l-54 30.302753c-7.3259212 4.111029-16.2842248 4.111029-23.610146 0l-54-30.302753c-7.53526997-4.228508-12.194927-12.15933-12.194927-20.755989v-59.7159721c0-8.5966592 4.65965703-16.5274806 12.194927-20.7559885l54-30.30275341c7.3259212-4.11102932 16.2842248-4.11102932 23.610146 0zm-80.805073 51.30049891v59.4742151c0 5.33677 2.897926 10.269094 7.599299 12.907326l53.2333248 29.872524c.6889768.266899 1.4236723.405136 2.1673762.405136 3.3137085 0 6-2.686291 6-6v-48.071351c0-7.8342799-4.3608877-15.0171862-11.3115925-18.6315528l-3.9625042-2.0605021c-.934508-.3978874-1.8572518-.8338901-2.7659776-1.3080079zm55.8290405 21.2682783c9.564678 4.9902667 16.803242 4.9902667 26.3679199 0l51.6981466-29.0233261c-1.273086-2.9149055-3.480935-5.402054-6.369655-7.0230944l-51.124751-28.673694c-4.5903189-2.57591294-10.2110831-2.57591294-14.801402 0l-51.0277398 28.673694c-2.8887203 1.6210404-5.0965694 4.1081889-6.3696549 7.0230944zm13.1709595-54.6520492c11.2500401 0 20.433902 5.5289753 20.9748091 12.4764404l.0251909 11.8985596c0 7.2487373-9.4020203 13.125-21 13.125s-21-5.8762627-21-13.125v-11.8985596c.566098-6.9474651 9.7499599-12.4764404 21-12.4764404zm.0024 21c9.742303 0 17.64-3.9488485 17.64-8.82s-7.897697-8.82-17.64-8.82-17.64 3.9488485-17.64 8.82 7.897697 8.82 17.64 8.82z"
            fill="#5a45ff"
            fillRule="nonzero"
          />
          <path
            d="m238.726302 88.5100134c0 6.7290056 1.73029 12.1361606 5.190921 16.2216286s8.026674 6.128171 13.698264 6.128171c5.479333 0 9.949249-2.066735 13.40988-6.200267 3.460632-4.133532 5.190921-9.5647193 5.190921-16.2937249 0-6.632877-1.682226-11.9198735-5.046729-15.8611482-3.364502-3.9412747-7.834418-5.9118825-13.409879-5.9118825-5.575462 0-10.141505 1.9946396-13.698265 5.9839786-3.55676 3.9893391-5.335113 9.3003674-5.335113 15.9332444zm53.639519-69.0680908v104.3951934h-9.450306c-2.502436 0-4.793343-1.403796-5.929531-3.633429-.609258-1.195599-.913888-2.358083-.913888-3.48745-1.941049 2.218342-3.484628 4.08174-7.137517 6.100442-3.652888 2.018701-8.483287 2.750744-13.193591 2.750744-9.99738 0-18.120129-3.508643-24.368491-10.526034-6.248363-7.017392-9.372497-15.8610953-9.372497-26.5313756 0-10.2857658 3.148166-18.9852782 9.444593-26.0987984 6.296426-7.1135203 14.299017-10.670227 24.00801-10.670227 5.575462 0 10.069409 1.0093357 13.481976 3.0280374 3.412568 2.0187016 5.791716 4.3738183 7.137517 7.0654205v-42.3925233zm59.684503 33.3084112v17.0146862h-2.151793c-12.592853 0-18.889185 6.8730955-18.889185 20.6194927v33.4526033h-16.726302v-70.2216287h10.84731c1.924322 0 3.629259 1.2404896 4.221407 3.0714395l1.657585 5.1253357c.798603-1.6637568 3.016945-5.3572969 6.899045-7.2096128 3.882099-1.8523159 8.385311-1.8523159 12.999486-1.8523159zm9.372496 52.0534042c0-5.9599761 1.946576-10.7423048 5.839787-14.3471292 3.89321-3.6048244 9.011984-5.8878456 15.356475-6.8491322l18.024032-2.7396528c3.460631-.4806433 5.190921-2.1628695 5.190921-5.046729 0-3.1722455-1.105463-5.7436484-3.316422-7.7142857-2.210959-1.9706374-5.527347-2.9559413-9.949265-2.9559413-4.229661 0-7.594113 1.1775583-10.093458 3.5327103s-3.941253 5.4071909-4.325768 9.1562083l-15.073637-.1441923c.672901-6.344491 3.490165-15.0680684 8.87337-19.5380507 5.383204-4.4699823 12.208236-6.7049399 20.4753-6.7049399 10.189637 0 17.711591 2.4512438 22.566088 7.353805 4.854497 4.9025613 7.281709 11.1988935 7.281709 18.8891856v34.8945259c0 4.614175.288382 8.363137.865154 11.246996l-8.99453.000003c-.950568 0-1.893056-.174555-2.780576-.514979-2.982835-1.144123-4.474252-3.005945-4.474252-5.585465-3.327514 5.545856-11.868083 8.263325-21.673206 8.263325-7.11352 0-12.857121-2.090767-17.230974-6.272363-4.373854-4.181596-6.560748-9.15618-6.560748-14.923899zm26.963952 8.074767c5.190947 0 9.396513-1.417877 12.616823-4.253672 3.220309-2.835795 4.83044-7.473933 4.83044-13.9145526v-3.1722297l-18.312416 2.7396529c-6.248363 1.0574152-9.372497 4.2296131-9.372497 9.5166894 0 2.499344.913208 4.638175 2.739653 6.416555 1.826444 1.77838 4.325752 2.667557 7.497997 2.667557zm85.217624-76.9432067c-2.787731 0-5.214943.7930495-7.281709 2.3791723-2.066766 1.5861227-3.100134 4.34978-3.100134 8.2910547v7.009962h16.293725v14.5634179h-16.293725v55.6582108h-16.870494v-55.6582108h-12.256342v-14.5634179h4.813803c4.110401 0 7.442539-3.3321381 7.442539-7.4425388 0-7.7864207 2.25899-13.9385621 6.777036-18.4566088 4.518047-4.5180466 10.42987-6.777036 17.735648-6.777036h8.651535v14.9959946zm45.265276-3.5160727v21.4846462h14.563418v14.8518024h-14.563418v32.5874498c0 3.076117.720954 5.311075 2.162884 6.70494 1.44193 1.393866 3.700919 2.090788 6.777036 2.090788h2.295985v14.851802h-6.765945c-6.536748 0-11.679554-1.850449-15.428571-5.551402-3.749018-3.700953-5.623498-8.819727-5.623498-15.356475v-35.3271028h-12.977303v-14.8518024h3.604806c3.55676 0 6.248322-1.0093357 8.074767-3.0280374 1.826444-2.0187016 2.739652-4.6621999 2.739652-7.9305741v-10.5260347zm28.11749-13.3100544h16.293725v42.9692924c1.345801-2.6916023 4.140889-4.9025266 7.553456-6.9212283s8.843764-3.3275136 14.419226-3.3275136c9.708994 0 17.467566 3.1352217 23.763993 10.2487419s8.401972 16.0681421 8.401972 26.3539078c0 10.6702803-2.081514 19.2588746-8.329876 26.2762656-6.248362 7.017392-14.947881 10.88097-24.94526 10.88097-4.710304 0-8.963934-1.086978-12.616823-3.10568-3.652889-2.018701-6.305638-3.882099-8.246688-6.100441 0 1.129367-.304629 2.29185-.913888 3.487449-1.136187 2.229634-3.427094 3.63343-5.929531 3.63343h-9.450306zm48.415323 85.6945668c3.55676-4.037403 5.335114-9.4685904 5.335114-16.2937246 0-6.8251343-1.73029-12.1842262-5.190921-16.0774366-3.460632-3.8932104-8.026674-5.8397864-13.698265-5.8397864-5.479333 0-9.997312 1.946576-13.554072 5.8397864s-5.335113 9.2523023-5.335113 16.0774366c0 6.7290056 1.778353 12.1121296 5.335113 16.1495326s8.074739 6.056075 13.554072 6.056075c5.575462 0 10.093441-1.970608 13.554072-5.911883zm38.355141-34.6726915h-6.910137v-16.637568h16.637568v.1220088h6.854678v70.2216287h-16.582109zm.576769-33.5302454c-2.114831-2.1148304-3.17223-4.6622014-3.17223-7.6421896s1.057399-5.5513911 3.17223-7.7142857c2.11483-2.1628947 4.662201-3.2443258 7.642189-3.2443258 3.076117 0 5.671552 1.0573993 7.786382 3.1722296 2.11483 2.1148304 3.17223 4.710265 3.17223 7.7863819 0 2.9799882-1.0574 5.5273592-3.17223 7.6421896-2.11483 2.1148303-4.710265 3.1722296-7.786382 3.1722296-2.979988 0-5.527359-1.0573993-7.642189-3.1722296zm58.83044-4.46996v21.4846462h14.563418v14.8518024h-14.563418v32.5874503c0 3.076117.720954 5.311074 2.162884 6.70494 1.44193 1.393865 3.700919 2.090787 6.777036 2.090787h2.295984v14.851803h-6.765944c-6.536748 0-11.679554-1.850449-15.428571-5.551402-3.749018-3.700953-5.623498-8.819727-5.623498-15.356475v-35.3271033h-12.977303v-14.8518024h3.604806c3.55676 0 6.248322-1.0093357 8.074766-3.0280374 1.826445-2.0187016 2.739653-4.6621999 2.739653-7.9305741v-10.5260347z"
            fill="#fff"
          />
        </g>
      </svg>
    | _ => ReasonReact.null
    },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~style=jsProps##style, ~name=jsProps##name, [||])
  );
