
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ʵ�ں������ܾ���Ȫˮ�峺��������ʽ��������Ϻ�������ǰ���е�����
��ȥ������ˮ����ɰʯ��������裬���ָо�����δ�������˾������������Ե��ġ�
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bottom",
  		"north" : __DIR__"bottom3",
  		"up" : __DIR__"smalllake",
  		"south" : __DIR__"bao",
	]));

	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",0);
	set("underwater",30);
	set("water_damage",20);
    	setup();
}


void init(){
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}
