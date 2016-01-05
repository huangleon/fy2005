inherit ROOM;

void create()
{
	set("short", "������");

	set("long", @LONG
�����Ƕ�������һյ����ֽ�����������бб������Ͳ��ڶ�ǽ�������
ͣ��ҡ�Ρ��谵�ĵƹ����������ˣ�һ��˥�����͵Ĳз��ˣ�������ª����������
���̡�һ��������´󺺣���һ�����Ǹ��ܸߴ�ĺ����ˣ������վ��[33m��[32m�ߡ� 
LONG);

	set("type","street");
	set("exits",([
		"down":__DIR__"broketower5",
	]) );

	set("item_desc", ([
		"��":	"һ���ƾɵĴ����������Ѿ�ûʣ�¼����ˣ��������������ȥ��jumpout window��\n",
		"window":	"һ���ƾɵĴ����������Ѿ�ûʣ�¼����ˣ��������������ȥ��jumpout window��\n",

	]));
	
	set("objects", ([
		__DIR__"npc/baili_changqing": 1,
		__DIR__"npc/deng":1,
		__DIR__"npc/hu_5":1
	]));
	set("indoors", "bawang");
	setup();

	set("coor/x",-15);
	set("coor/y",10);
	set("coor/z",40);
}



void init(){	
	add_action("do_jump","jumpout");
}


int do_jump(string arg){
	
	object me, ob, room;
	
	me = this_player();
	
	if (!arg || arg!="window")	return 0;

	if (ob=present("baili"))
		return notify_fail(ob->name()+"����ص��������ǰ�����Ƿ�֮�أ��������ģ�����������ȥ�ɡ�\n");
		
	message_vision("$NԾ�ϴ�̨�����¿��˿�������������ȥ��\n", me);
		
	room = find_object("/d/bawang/undertower2");
	if(!room) room=load_object("/d/bawang/undertower2");
	me->move(room);
	message("vision", me->name()+"�������滺������������\n", environment(me), me);
	
	return 1;
}