// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ·��������ϸ�۲죬���߲ݴ�֮�о�Ȼ�����ɭɭ�׹ǣ����ж��вн�����
Ȼ����Щ�������ˣ�ֻ��Ϊ�ε����������������⡣һ�����ɵ���ʯ���ź��
·�ϣ�������飢һ����ţ�����Ϊ�ˣ������������Ե�ʮ�ֹ��죬�㲻�ɵ��ľ�
������
LONG
        );
   	set("exits", ([ 
      		"east" : __DIR__"valley",
      		"southdown" : __DIR__"tianti1",
   	]));
   	set("objects", ([
      		__DIR__"obj/grass": 1,
   	]) );
	set("outdoors","laowui");
	set("coor/x",160);
	set("coor/y",190);
	set("coor/z",20);
	setup();

}

void init(){
	add_action("do_search","search");
}


int do_search(){
	object item, me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	message_vision("$N������ȥ���Ҳݴ�������������\n",me);
	if (me->query("maze/����Ǯ���޼�") && !me->query("maze/����������") && !random(10)) {
		tell_object(me,"������ֵ�һ����������һ�����������¡�\n");
		item = new(__DIR__"obj/sword");
      		item->move(this_object());
      		me->set("maze/����������",1);	// Let the mark on player to take care of it.
      	} else
      		tell_object(me,"��ʲôҲû�ҵ���\n");
      	me->start_busy(1);
      	return 1;
}
	
