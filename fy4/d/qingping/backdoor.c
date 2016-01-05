inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��԰�Ķ�ǽ��һ��С[37mľ��[32m��ľ��������һ��С���ţ�һ����������ʯ��С·��
�ѵش�ľ��ǰ��������ʧ�ڻ����С���Ϊ����ƽʱ���������ߣ����ϵ�ʯ���в�֪
��ʱ����Щ��֪���Ļ��ݣ���������Ұ����ȴҲ���ķҷ�������
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "westup" : __DIR__"bridge",
   "northwest" : __DIR__"northpond.c",	
   "south" : __DIR__"southpond1.c",	
   ]));

   set("objects", ([
      __DIR__"obj/cao": 1,
   ]) );
	set("item_desc", ([
		"door" : "С�Ž����ţ���֪������ͨ�����\n",
		"ľ��" : "С�Ž����ţ���֪������ͨ������ ��\n",
	]));
   set("outdoors","qingping");
	set("coor/x",20);
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
	if(query("exits/east")) {
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");
	}
	message_vision("$N̽����Сľ����һ�ƣ���֨֨����С�����ִ򿪣�¶��һ��������С����\n", me);
	set("exits/east", __DIR__"path");
	room = find_object(__DIR__"path");
	if(!objectp(room)){
		room = load_object(__DIR__"path");
	}
	message("vision", "С�ű��˴�����򿪡�\n", room);
	room->set("exits/west", __DIR__"backdoor");
	call_out("close_path", 5);
	return 1;
}

void close_path(){
	if( query("exits/east") ) {
		message("vision","��֨֨����С����������ס��С����\n",this_object() );
		delete("exits/east");
	}
}

void reset()
{
   object *inv;
   object item1, cao;
   ::reset();

   cao = present("cao", this_object());
   inv = all_inventory(cao);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(cao);
   }
}

