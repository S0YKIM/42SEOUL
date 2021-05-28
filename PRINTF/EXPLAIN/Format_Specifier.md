# 형식문자열(FORMAT)

⭐PROTOTYPE
===========


      int printf(const char* format, ...)

* `printf()` 의 두 번째 인자인 `...` 을 `가변인자` 라고 부른다.
* 가변인자로는 아무 것도 넘겨주지 않을 수도 있고 여러 개를 넘겨줄 수도 있다.
</br>
</br>
</br>


# How to Create A Function Using Variable Arguments

⭐HEADER FILE
=============

      #include <stdarg.h>
      
* 이 헤더파일에 가변인수 함수를 만드는 데에 필요한 `매크로` 들이 들어있다.
* 최소 1개 이상의 고정 인수가 필요하다.
* 가변인자 `...` 는 파라미터의 마지막 순서에 있어야 한다.

</br>
</br>

⭐MACROS
========


https://velog.io/@hidaehyunlee/형식태그와-서식지정자-printf-함수의-옵션-알아보기