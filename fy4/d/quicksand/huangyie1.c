
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١������������
�綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ����һ����
�����۵Ĺٵ��������Ͷ�����չ��һ������ָ��·���С�꣬����д��[33m�������䡻[32m
LONG
        );
        set("exits", ([ 
	  "east" : __DIR__"huangyie4",
	  "west" : __DIR__"sandroad",
	  "south" : AREA_DEATH"ghostinn",
	  "southeast" : __DIR__"huangyie3",
	  "northeast" : __DIR__"huangyie2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 3,
        ]) );

	set("coor/x",-1010);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	if(me->is_ghost()){
		room = load_object(AREA_DEATH"ghostinn");
		me->move(room);
		return notify_fail("��е�һ����ѣ���ƺ������ܶ���Ӱ����ǰ�ι���\n");
	}
	return 1;

}
