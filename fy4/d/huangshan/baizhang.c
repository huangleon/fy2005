// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
��ɽ��������֮һ�������ֱ�¶��������ɹ���ͤԶ����Ϊ׳�ۡ����˽��ۣ�
ֻ���ͱ��絶������ݲ������ٲ�����һ����ɫ��˿�д������£�ײ������ʯ�ϣ�
�������齦��ˮ��������һ������֮���������������һ�����ķ��顣
LONG
        );
	set("exits", ([ 
		"south" : __DIR__"qingluan",
  		"northwest" : __DIR__"mroad1",
	]));
    set("objects", ([
        __DIR__"npc/shui" : 1,
    ]) );
	set("resources/water",1);
    set("outdoors", "huangshan");
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",10);
	setup();
    replace_program(ROOM);
}
