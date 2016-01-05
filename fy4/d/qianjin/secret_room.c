inherit ROOM;
void create()
{
        set("short", "�ײ�");
        set("long", @LONG
�ײ�������ʪ�������˱ǡ����ϲյĸ������������Ǻϡ�һյ�����ĵ�������
�����ҡ�ڶ�����֨֨�����ı���������壬�ƺ�����ˮ����������ն��ϵ��Ű�
�����ӡ��յױ��䣬�ƺ����Ըе���ˮ��������
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"sr1",
  		"east" : __DIR__"sr2",
	]));
    set("item_desc", ([
    	"�������" : "���ӵ�һͷ���ڲն���һ��ľ���ϣ����ƺ������������ӣ������졡����䣩��\n",
    	"rope" : "���ӵ�һͷ���ڲն���һ��ľ���ϣ����ƺ������������ӣ������졡����䣩��\n",
    	"����" : "���ӵ�һͷ���ڲն���һ��ľ���ϣ����ƺ������������ӣ������졡����䣩��\n",
    	"cord" : "���ӵ�һͷ���ڲն���һ��ľ���ϣ����ƺ������������ӣ������졡����䣩��\n",
    ]));
    set("objects", ([
        __DIR__"npc/prisoner" : 3,
    ]) );

	set("coor/x",-60);
	set("coor/y",15);
	set("coor/z",-10);
	setup();
}

void init(){
	add_action("do_pull", "pull");
}

int do_pull(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "cord" && arg != "����")) {
		return 0;
	}
	if(!query("exits/up")) {
		message_vision("$N����һ��ͷ���ϵ����ӣ�һ��ľ�巭����¶�����ϵ�ͨ·��\n", me);
		set("exits/up", __DIR__"eting");
		room = find_object(__DIR__"eting");
		if(!objectp(room)){
			room = load_object(__DIR__"eting");
		}
		room->set("exits/down", __DIR__"secret_room");
		call_out("close_path", 10);
	} else {
		message_vision("$N����һ��ͷ���ϵ����ӣ�һ��ľ�嵲�������ϵ�ͨ·��\n", me);
		delete("exits/up");
		room = find_object(__DIR__"eting");
		if(!objectp(room)){
			room = load_object(__DIR__"eting");
		}
		if(room->query("exits/down")){
			room->delete("exits/down");
		}
	}
	return 1;
}

void close_path()
{
	object sect;
	if( !query("exits/up") ) return;
	delete("exits/up");
	message("vision", "ľ�廬�ϵ�ס�����ϵĳ��ڡ�\n", this_object());
	sect = find_object(__DIR__"eting");
	if(!objectp(sect)) {
		sect = load_object(__DIR__"eting");
	}
	sect->delete("exits/down");

}
