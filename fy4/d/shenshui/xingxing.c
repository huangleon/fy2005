// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����С¥");
        set("long", @LONG
����¥����ֻ�����ܳ����Ϊ��ɫ���ı�Ҳ�Ǻ�ɫ�������ϱ���һ�ȴ���΢΢
͸��Щ��ɫ�⣬��ֻ�����������ϵ��͵Ʒ���΢���Ĺ⣬��������һ��齣�������
�ż򵥵ı��졣���ڴ���һ���������������������������������ʲô�����̲�
ס����������
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"ruanhong",
   ]));
   set("objects", ([
      __DIR__"npc/lingyu" : 1,
   ]) );
  
   set("item_desc", ([
      "window": "�ٴ��¿���ֻ��Σ�°ٳߣ���ɫ�ĺ����Ĵ��Ű��ߵ���ʯ��
����ԴӴ���������ȥ�������⡡������������ \n",
      "��": "�ٴ��¿���ֻ��Σ�°ٳߣ���ɫ�ĺ����Ĵ��Ű��ߵ���ʯ��
����ԴӴ���������ȥ�������⡡������������ \n",
   ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void init(){
    add_action("do_climb", "climb");
    add_action("do_listen", "listen");
    add_action("do_answer", "answer");
}

int do_climb(string arg)
{
    	object me;
    	int cl;
    	me = this_player();
    	cl = (int)me->query_cps();
    	if(!arg || (arg != "window" && arg != "��")){
        		return 0;
    	} 
   		if (cl >= 20 || random(100)>90) {
        	message_vision("$N�������ڣ�����������ȥ��\n\n", me);          
        	call_out("fall_out", 1, me);
        	me->start_busy(2);
    	} else {
        	tell_object(me, "���������ڣ����⿴�˿����е���ԥ�������԰ɣ�\n\n", me);
        	message("vision", me->name()+"�������ڣ����⿴�˿�����ɫɷ�׵�������������\n\n", environment(me), me);
    	}   
    	return 1;
}

int fall_out(object me){
    	int ml, cl;
    	object room;
    	
    	if (!me || me->is_ghost() || environment(me)!=this_object())	return 1;
	
		if (me->query_skill("move")<50) {
       		tell_object(me, "��ֻ������������׹�䣬������������ҽ�̤��һ�Ŵ��ҷ��г�����С
��������һ��С�����ˣ����½�������Ҳ���˻�����ͨһ����������ˮ�С���\n\n");
    	} else {
        	tell_object(me, "��ֻ������������׹��...׹��....�ƺ�׹���޵׵���Ԩ��������ͨһ
����������ˮ�С�\n");
    	}
    	
    	room = find_object(__DIR__"yadi");
    	if(!objectp(room)) room = load_object(__DIR__"yadi");
    	me->move(room);
    	message("vision", "�������һ�źں�����������������£���ͨһ�����������Ե�ˮ�С�\n", environment(me), me);
    	return 1;
} 

int do_listen(string arg){
    	object me, obj;
    
    	me = this_player();
    	if(!arg || (arg != "wave" && arg != "����" && arg != "������" && arg != "haitao")) {
        	return notify_fail("��Ҫ��ʲô��\n");
    	}
    	message_vision("$N������������Ĵ򰶱ߵ�������\n", me);
    	if(obj = present("ling yu", this_object())){
    	if(!me->query_temp("marks/lingyu_asked")){
	    	message_vision("$N΢Ц�Ŷ�$n����������һ�����ص����磬����������������˵Ĵ��ڣ���
���������򡡣���󣯣�������\n", obj, me);
    		me->set_temp("marks/lingyu_asked", 1);
    	} else {
    		tell_object(me, "ֻ����һ�����γ��������ʯ��������\n");
    	}
    }
    return 1;
}

int do_answer(string arg){
    	object ly, me, mask;
    
    	me = this_player();
    	if(!arg || (arg != "yes" && arg != "no" && arg != "dunno")) {
        	return 0;
    	} 
    	if (!me->query_temp("marks/lingyu_asked")) {
        	return 0;
    	} 
    	if(ly = present("ling yu", this_object())){
        	ly->answer_react(me, arg);
    	}
	return 1;
}
