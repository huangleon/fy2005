
inherit ROOM;

void create()
{
        set("short", "��̨��");
        set("long", @LONG
վ��ɽ�嶥�ˣ�����ң������·�������֣���ʱƮ��������ס������ߡ���
�������������֣����¶����絶�����ɣ�������ɽ·ǧ���ٻأ�·�������ɳ��֣�
�羰���������һ��
LONG
        );
    set("exits", ([ 
        "southdown" : __DIR__"canglong",
	]));
	set("objects", ([
		__DIR__"obj/tree" : 1,
		__DIR__"npc/baiyun" : 1,
	]));  
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-48);
	set("coor/z",40);
	setup();
    replace_program(ROOM);
}

