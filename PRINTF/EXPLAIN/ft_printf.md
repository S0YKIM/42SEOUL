⭐ print_var_args
================

- `tag->type` 이 `cspdiuxo%` 중에 무엇인지 검사하여 `print_OOOOO` 선택

- `tag->zero = 0` if 문에서 `0` 플래그를 끄는 경우?

</br>

*(1) `tag->minus == 1`
- 좌측 정렬인 경우에는 무조건 `0` 플래그가 무시된다

</br>

*(2) `c`, `s`, `%` 을 제외한 `tag->precision > -1`
- 정밀도가 존재하는 경우에는 정밀도 옵션을 통해 `0` 을 채워주기 때문이다.
- 하지만 `c`, `s`, `%` 의 경우에는 정밀도가 `0`을 채우는 역할을 하는 것이 아니다.
- 정밀도는 무시되거나 문자열을 자르는 기능을 할 뿐, `0`플래그와 `width`가 존재할 때에 `0`이 채워진다.

      `c` 와  `%`: 정밀도 옵션이 완전히 무시된다.
      `s`: 정밀도 옵션이 문자열의 길이보다 작을 경우 잘라낸다. 

- ex) `printf("%010.3c\n", 'a');`     -> 000000000a 출력
- ex) `printf("%010.3%\n");`          -> 000000000% 출력
- ex) `printf("%010.3s\n", "abcde");` -> 0000000abc 출력 