inherit ROOM;
void create()
{
  set("short","���ش��");
  set("long",@LONG
����һ�������������ֱ�����������������͵�������Ͽ�����Լ��������
�ǵĳ��ţ����Ǵ�ǰ��[33m��̩����԰��[32m�������������Ƶ���Ů־ʿ�ǽ�����լ����
�ڣ���ϧ����ѱ���͢�������Υ�´��Ϊ�ɲ��һƬ���档����ͨ��Ȫ�Ǽ��ϣ�
����ɽ���ؽ硣
LONG
  );
  	set("exits",([
         "west" :AREA_LAOWU"road2",
         "east" :__DIR__"shanjiao",
               ]));

        set("outdoors", "jinan");
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

