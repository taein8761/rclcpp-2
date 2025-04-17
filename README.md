# rclcpp-2
   
1. 1번을 수정하여 문자열 대신에 정수값을 0으로 초기화하고 1씩 증가시키면서
   퍼블리시하는 패키지 pub2-1를 작성하시오.
+ 토픽 메시지 인터페이스는 std_msgs/msg/Int32을 사용할 것
   ![스크린샷 2025-04-10 165647](https://github.com/user-attachments/assets/d37b0d34-4f61-495a-a354-466df1acb3bf)
  
2. 1번을 수정하여 키보드로부터 실수값 3개를 입력받아 퍼블리시하는 패키지 pub2-2를 작성하시오.
+ 토픽 메시지 인터페이스는 geometry_msgs/msg/Vector3을 사용할 것
+ 패키지 생성시 의존패키지에서 std_msgs를 geometry_msgs으로 수정해야함
+ 소스파일작성시 헤더파일명과 클래스명을 수정해야함
+ CMakeLists.txt의 add_executables 명령에서 의존 패키지를 std_msgs에서 geometry_msgs으로 수정해야함
  ![스크린샷 2025-04-10 165626](https://github.com/user-attachments/assets/a86e05ff-c744-494a-8dd2-4f3979e1fe0e)
  
3. Turtlesim 패키지의 teleop_turtle 노드를 대신하는 패키지 pub2-3를 작성하라.
+ 거북이의 선속도와 각속도를 적당한 값으로 전송하여 거북이가 일정
  한 반경으로 무한히 회전하도록 /turtle1/cmd_vel 토픽을 발행할 것
+ geometry_msgs/msg/Twist 를 사용할 것(11페이지 참고)
+ 패키지 생성시 의존패키지에서 std_msgs를 geometry_msgs으로 수정해야함
+ 소스파일작성시 헤더파일명과 클래스명을 수정해야함
+ CMakeLists.txt의 add_executables 명령에서 의존 패키지를 std_msgs에서 geometry_msgs으로 수정해야함
+ turtlesim(subscriber 역할수행) 노드를 실행하고 테스트 할 것
  ![스크린샷 2025-04-10 165434](https://github.com/user-attachments/assets/9d8aebff-dfac-46f9-a7f3-544aeac2ab77)
