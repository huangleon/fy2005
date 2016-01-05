// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����ɽ��Խ��һ��ʯ��������ȥ����һ���ţ�ԶԶ��ȥ���ֺ�������ڿգ���
�Ͽ������ˣ�ʯ�������С���𽡱���֡�ʯ����ͷ����ʯ���и����м�����������
�������������ˡ�����ʯ����һ���ʯ���������Զȴ�����ѷ죬�����ݲ�����
LONG
        );
	set("exits", ([ 
  		"eastup"  : __DIR__"taohua",
  		"south" : __DIR__"renzi",
  		"southwest" : __DIR__"zuishi",
  		"north" : __DIR__"baizhang",
  		"westup" : __DIR__"mroad2",
	]));
    set("objects", ([
    	__DIR__"obj/stone" : 1,
    	__DIR__"obj/stone4" : 1,
    	__DIR__"npc/monkey2" : 1,
    ]) );
    
    set("outdoors", "huangshan");
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void reset () {
    object *inv;
    object item1, stone4;
    ::reset();
    
    stone4 = present("stone", this_object());
    inv = all_inventory(stone4);
    if( !sizeof(inv) ) {
    	item1 = new(__DIR__"obj/shier");
        item1->move(stone4);
    }   
}
