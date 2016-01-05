inherit ROOM;

void create()
{
        set("short", "�µ�");
        set("long", @LONG
���ܶ��������ͱڣ��ϱ�����һ�˶�ߵľ�����������û��ϣ������ȥ������
��ֻ��һ��������Ŀռ䣬���������ϸɳ����ֻͺӥ�ڸ߸ߵ������ϰ��裬��ʱ
�˿̣������ᵽ���ɵĿ��֡�
LONG);

        set("type","road");
       set("outdoors", "wolfmount");
	set("coor/x",80);
	set("coor/y",20);
	set("coor/z",-60);
	setup();

}

void init(){
	add_action("do_climb", "climb");
}

int do_climb(){
	object me, room;
	int i;
	me = this_player();
	i = me->query_skill("move",1);
	if(i<1){
		message_vision("$Ņͷ���˿����ܵ��ͱڣ����ɵó�̾��һ������\n", me);
		tell_object(me, "����Ŀǰ�����ֿ�����û�п���������ȥ�ˡ�\n");
		tell_object(me,"����ڰ���Ϊʲô��һ���Ṧ������ѧ�أ���\n");
	} else {
		message_vision("$Ņͷ���˿����ܵ��ͱڣ���������˼���������ȥ��\n", me);
		me->start_busy(3);	
		call_out("do_fliping", 3, me);
	}
	return 1;
}
int do_fliping(object me){
    object room;
    
    if( !me->is_ghost()) {   
    	room = find_object(__DIR__"moonrock");
    	if(!objectp(room)){
    		room = load_object(__DIR__"moonrock");
    	}
    message("vision", me->name()+"Խ��Խ�����ν�����ʧ�����ˡ�\n", environment(me), me);
    me->move(room);
    message_vision("$N˳�Źȱ�����������\n", me);
    }
    return 1;
}
