
inherit ROOM;
string bush();
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
����һƬ������ľ��ɽ�¡��Ͱ�����ľ���ص�������·���У��������������
ʲô���������һƬï�ܵĴ��֡�������ֻ��ɽ���ص��������������ɫ��������
��һ��ɽˮͼ�������Ȼ�������ںδ���
LONG
        );
    	set("exits", ([ 
		"south" : __DIR__"milinop",
	]));
   	set("item_desc", ([
   		"��ľ" : (: bush :),
   		"bush" : (: bush :),
   		"guanmu" : (: bush :),
   	]));
    	set("outdoors", "huashan");
	
	set("coor/x",-5);
	set("coor/y",-40);
	set("coor/z",27);
	setup();

}

string bush(){
	object me;
	me = this_player();
	tell_object(me, "��ľ���ܣ��ƺ���Ҫ�����ſ���ͨ�С��������\n");
	add_action("do_chop", "chop");
	return "";
}

int do_chop(string arg)
{
    	object obj, me, bush;
    	if(!arg || (arg!="bush" && arg != "��ľ" && arg != "guanmu")){
    		return notify_fail("��Ҫ����ʲô��\n");
    	}
    	me = this_player();
    	obj = me->query_temp("weapon");
    	if( !obj ){
    		tell_object(me, "������֣���ô����\n");
    		return 1;
    	} else if( obj->query("flag") == 4 ) {
    		if( !query("exits/north") ) {
    			set("exits/north", __DIR__"guanmu");
    			message_vision(sprintf("$N�����е�%s����һ���򱱵�·��\n",obj->name()),me);
			bush = find_object(__DIR__"guanmu");
			if(!objectp(bush)){
				bush = load_object(__DIR__"guanmu");
			}
			bush->set("exits/south", __DIR__"duanshan");
    			me->start_busy(1);
    		} else {
    			message_vision(sprintf("$N�����е�%s���ľһ���ҿ���\n",obj->name()), me);
    		}
	} else {
		message_vision("$N���Ź�ľһͨ�ҿ���\n", me);
	}
	call_out("close_path", 30);
	return 1;
}

void close_path(){
	object room;
	
	if(query("exits/north")){
		message("vision", "��ľ��֦Ҷ���ص�ס�˱����·��\n", this_object());
		delete("exits/north");
	}
	room = find_object(__DIR__"guanmu");
	if(!objectp(room)){
		room = load_object(__DIR__"guanmu");
	}
	if(room->query("exits/south")){
		message("vision", "��ľ��֦Ҷ���ص�ס�������·��\n", room);
		room->delete("exits/south");
	}
}
