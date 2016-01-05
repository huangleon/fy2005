
inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
��ɫ���ǰ��һ��С·�����������С·���������Ӳݣ��ƺ��Ѿ�δ���˴���
���߶���С·�����ǲԾ��ľްع��ɣ�������ʯ���������ݺ�����ֻ�в�ʱ������
ȥ��С�����������ļž���
LONG
        );
    set("exits", ([ 
		"east" : __DIR__"hpath2",
	]));
 	set("item_desc", ([
 		"��ɫ���" : "��ɫ��ʵ�һ���ƺ�û�а������Ҳ������ƿ������������������\n",	
		"���" : "��ɫ��ʵ�һ���ƺ�û�а������Ҳ������ƿ������������������\n",
 		"curtain" : "��ɫ��ʵ�һ���ƺ�û�а������Ҳ������ƿ������������������\n",
 	]) );  
    	set("objects", ([
    		__DIR__"obj/stone2" : 1,
    		"/obj/animal/songshu" : 2,
    	]));
    	set("outdoors", "huashan");
	set("coor/x",-9);
	set("coor/y",15);
	set("coor/z",-10);

	setup();
}

void init(){
	add_action("do_open", "open");
}

int do_open(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "���" && arg != "��ɫ���" && arg != "curtain")) {
		return 0;
	}
	if( !query("exits/west") ) {
		room = find_object(__DIR__"path1");
		if(!objectp(room)) {
			room = load_object(__DIR__"path1");
		}
		message_vision("$N�ƿ���ɫ��ʵ�һ�ǡ�\n", me);
		set("exits/west", __DIR__"path1");
		message("vision", "�����ƿ���ɫ��ʵ�һ�ǡ�\n", room);
        room->set("exits/east", __DIR__"hpath1");
        call_out("close_path", 5);
	}
	return 1;
}
void close_path(){
	object room;
	
	if( !query("exits/west") ) {
		return;
	}
	if(!objectp(room = find_object(__DIR__"path1"))){
		room = load_object(__DIR__"path1");
	}
	message("vision", "��ɫ��ʴ��µ�ס��ȥ·��\n", this_object());
	message("vision", "��ɫ��ʴ��µ�ס��ȥ·��\n", room);
	room->delete("exits/east");
	delete("exits/west");

}

int valid_leave(object me, string dir){
	if(dir == "west") {
		message_vision("$N�����������֮�С�\n", me);
	}
	return 1;
}
