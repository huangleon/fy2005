// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����һƬ�ȵأ������֮�У��ƺ�֮�󣬾�Ȼ��һ���˹�����ĵ�ɽ·������
��ʯ�̾ͣ�������Է��򻬣���Ϊ���£��Լ��õ�������֮ʱ����������������
��Ѫ��һ·��������ϸ�۲죬���߲ݴ�֮�о�Ȼ�����ɭɭ�׹ǣ����ж��вн���
��Ȼ����Щ�������ˣ�ֻ��Ϊ�ε����������������⡣
LONG
        );
        set("exits", ([ 
  		"southwest" : __DIR__"gudi",
  		"northup" : __DIR__"tianti2",
	]));
	set("outdoors","laowu");
	set("coor/x",160);
	set("coor/y",180);
	set("coor/z",10);
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
	tell_object(me,"��ʲôҲû�ҵ���\n");
      	me->start_busy(1);
      	return 1;
}