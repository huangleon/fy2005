
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
  		"west" : __DIR__"bottom",
  		"eastup" : __DIR__"yadi",
  		"north" : __DIR__"bottom3",
	]));
	set("coor/x",-60);
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
