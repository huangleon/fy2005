
inherit ROOM;

void create()
{
        set("short", "��ջ��");
        set("long", @LONG
�±��ƴ�ֱ��Ȼ�������ɽ����ȴ����һ��ջ����ľ׮����ȭͷ���С��ʯ
���ڣ������̼���ľ�壬���������߲������˲�����С����¿�������һƬ��
�̣�Ϫ���ݺᣬ��ɫ���ˡ���ǰ�������ٹ��£�ˮ����¡������׳�ۡ� 
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"changpu",
  		"northup" : __DIR__"zd2",
	]));
	set("objects", ([
		__DIR__"obj/yabi" : 1,
		__DIR__"npc/chiyang" : 1,
	]) );   
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",15);
	set("coor/z",-20);
	setup();
    replace_program(ROOM);
}

