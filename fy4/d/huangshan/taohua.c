// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�һ���");
        set("long", @LONG
�嶥�������ȴҲ��С��һ������Сͤ�����嶥�ı�Ե�����м�����һ����
ש�����ߵĽ�����վ�ڷ嶥���¿����������޼ʵ�Ⱥ��ɽ�ͺͿ������߼ʵ���ɫ��
ɽ��İ��������������ƣ���Ȫ����ſ����飬Ƕӳ��Ⱥ���С���Զ����Լ�ɼ�һ
Сʯ�ź����ɽ������
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"ciguang",
  "eastdown" : __DIR__"wenquan",
  "southwest"  : __DIR__"taoyuan",
  "westdown" : __DIR__"qingluan",
]));

        set("outdoors", "huangshan");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
