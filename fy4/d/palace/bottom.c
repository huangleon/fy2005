
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
  		"east" : __DIR__"bottom1",
  		"west" : __DIR__"bottom2",
	]));
        set("objects", ([
        	__DIR__"npc/fish" : 2,
        	__DIR__"npc/shrimp" : 2,
        ]) );

	set("coor/x",-70);
	set("coor/y",60);
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