
inherit ROOM;
int fall(object me);
void create()
{
        set("short", "��ľ��");
        set("long", @LONG
���ܶ��ǵͰ��Ĺ�ľ�����ص����Ĺ�ľ����������֮��������ľ֦Ҷ�϶���
�м��Ĵ̣���֦Ҷ�������ֱ����գ������������һ������������ʹ��
LONG
        );
 	set("objects", ([
 		__DIR__"obj/bush" : 1,
 	])); 
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",-38);
	set("coor/z",27);
	setup();
}

void init(){
	object me;
	me = this_player();
	add_action("do_chop", "chop");
	if (!userp(me))	return;
		
	if( me->query_temp("followcrow")) {
		call_out("fall", 4, me);	
	} else if(!random(10)){
		call_out("fall", 4, me);
	}  
}

int fall(object me){
	object room;
	
	if(! me || !interactive(me) || environment(me) != this_object()){
		return 0;
	}
	tell_object(me, "�����һ�ɣ������Ȼ������ȥ���ھ������У���׹��ɽ�¡�\n");
	message("vision", "������һ�����С���~~~����" + me->name() + "����������׹ȥ��\n", 
			environment(me), me);
	room = find_object(__DIR__"yadi");
	if(!objectp(room)){
		room = load_object(__DIR__"yadi");
	}
	message("vision", "ֻ��һ�����С���~~~~~���漴һ�����������ԡ�\n", room, me);
	me->move(room);
	me->unconcious();
}

int do_chop(string arg)
{
    object obj, me, room;
    if(!arg || (arg != "bush" && arg != "��ľ" && arg != "guanmu")) {
    	return notify_fail("��Ҫ����ʲô��\n");
	}
    me = this_player();
    obj = me->query_temp("weapon");
    if( !obj ){
    	tell_object(me, "������֣���ô����\n");
    	return 1;
    } else if( obj->query("flag") == 4 ) {
    	if( !query("exits/south") ) {
    		set("exits/south", __DIR__"duanshan");
    		message_vision(sprintf("$N�����е�%s����һ�����ϵ�·��\n",obj->name()),
            		me);
			room = find_object(__DIR__"duanshan");
			if(!objectp(room)){
				room = load_object(__DIR__"duanshan");
			}
			room->set("exits/north", __DIR__"guanmu");
    		me->start_busy(1);
    	} else {
    		message_vision(sprintf("$N�����е�%s���ľһ���ҿ���\n",obj->name()),
            		me);
    	}
	} else {
		message_vision("$N���Ź�ľһͨ�ҿ���\n", me);
	}
	call_out("close_path", 30);
	return 1;
}

void close_path(){
	object room;
	
	if(query("exits/south")){
		message("vision", "��ľ��֦Ҷ���ص�ס�������·��\n", this_object());
		delete("exits/south");
	}
	room = find_object(__DIR__"duanshan");
	if(!objectp(room)){
		room = load_object(__DIR__"duanshan");
	}
	if(room->query("exits/north")){
		message("vision", "��ľ��֦Ҷ���ص�ס�˱����·��\n", room);
		room->delete("exits/north");
	}
}
