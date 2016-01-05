inherit ROOM;
void create()
{
        set("short", "��ҰС��");
        set("long", @LONG
�߸ߵ�Χǽ����һ��СС��ľ�ţ�ǰ����һ����С·��������С���ϲ�����Ұ
�ݣ��������������������߶���С·���ѵ�����Զ������û��ǰ����һƬ�����У�
�����ٹ�ȥ����ΡΡ�ĸ�ɽ��
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
	   "east" : __DIR__"path1",	
   ]));
	set("item_desc", ([
		"door" : "С�Ž����ţ�������Ȼ������\n",
		"ľ��" : "С�Ž����ţ�������Ȼ������\n",
	]));
	set("outdoors","qingping");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}

void init(){
	add_action("do_push", "push");
}

int do_push(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "door" && arg != "Сľ��" && arg != "ľ��")){
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if(query("exits/west")) {
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");
	}
	message_vision("$N̽����Сľ����һ�ƣ���֨֨����С�����ִ򿪡�\n", me);
	set("exits/west", __DIR__"backdoor");
	room = find_object(__DIR__"backdoor");
	if(!objectp(room)){
		room = load_object(__DIR__"backdoor");
	}
	message("vision", "С�ű��˴�����򿪡�\n", room);
	room->set("exits/east", __DIR__"path");
	call_out("close_path", 5);
	return 1;
}

void close_path(){
	if( query("exits/west") ) {
		message("vision","��֨֨����С����������ס��С����\n",this_object() );
		delete("exits/west");
	}
}
