// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�µ�");
        set("long", @LONG
ʯͷ�Ǻ�ɫ�ģ����ƺ�Ҳ�Ǻ�ɫ�ģ���ͷ���µ׵�ʯͷ�Ͻ������ɫ��ˮ
�������þ�����Ҳ���Ѳ�����ͷ��������ֻ�о����˵׵�ˮ���ƺ��Ƚ�ƽ�ȡ�����
Ȼ�����������������޷�����ġ�
LONG
        );
    set("outdoors","shenshui");
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-60);
    setup();
}

void init(){
    	if(interactive(this_player())){
        	call_out("do_flush",30,this_player());
    	}
    	add_action("do_dive", "dive");
}

void do_flush(object me)
{
   		object room;
		string nroom;
		int level;
		
    	if(!me || environment(me) != this_object()) {
        		return;
    	}
    	
    	level = F_LEVEL->get_level(me->query("combat_exp"));
    	if (level < 18)	nroom = "ocean0";
    	else if (level < 24) nroom = "ocean1";
    	else if (level < 26) nroom = "ocean2";
    	else nroom = "ocean3";    	        
        room = find_object(__DIR__+ nroom);
        if(!objectp(room)) room= load_object(__DIR__+ nroom );
        me->move(room);
 
}


int do_dive(){
	object me, obj;

	me = this_player();
	message_vision("$Nһ������������ˮ�С�\n", me);
    	obj = find_object(__DIR__"midsea");
    	if(!objectp(obj)) {
        	obj = load_object(__DIR__"midsea");
    	}
    	if (obj->query("underwater") > me->query_skill("swimming",1))
		return notify_fail("�����Ӿ����̫�û����ȥѽ��\n");
    	
    	me->move(obj);
    	message("vision", me->name() + "��������ߵ�ˮ�С�\n", environment(me), me);
    	return 1;
}
