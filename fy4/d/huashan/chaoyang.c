
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�˷�λ�ڻ�ɽ���֮�������Ͽ�����ɽ�嶥������һ��޴����ʯ����ͺͺ��
ʯ��֮�Ϻ�����֦����������Ԯ��ʯ����ֻ�м�����������ѣ������ʵǵ��˱���
�ֽŲ��ò��ܴﵽ���ۡ���������һ���·���ӳ���ƺ�֮�С�
LONG
        );
    set("exits", ([ 
  		"northwest" : __DIR__"xiaodao1",
	    "southeast" : __DIR__"yaozi",
	    "southdown" : __DIR__"ziqi",
	]));
   
   		set("item_desc", ([
 		"ʯ��": "ʯ�ڶ��ͣ�����ֻ�м�����������ѡ�\n",
   		"cliff": "ʯ�ڶ��ͣ�����ֻ�м�����������ѡ�\n",
 	]) );  
   		
    set("outdoors", "huashan");

	set("coor/x",-4);
	set("coor/y",-53);
	set("coor/z",33);
	setup();
}

void init(){
    add_action("do_climb", "climb");
}

int do_climb(string arg){
    object me;
    
    me = this_player();
    if(!arg || arg == "") {
        return notify_fail("��Ҫ��ʲô��\n");
    }
    if(me->is_busy()) {
        return notify_fail("������æ��\n");
    }
    if(arg == "up" || arg == "cliff"  || arg == "ʯ��" ) {
        message_vision("$N�ֽŲ��ã����ӽ�����ʯ�ڣ�����������ȥ��\n", me);
        me->start_busy(3);
        call_out("fliping", 3, me);
    } 
    return 1;
}

int fliping(object me){   
    object ob;
	
    ob = find_object(__DIR__"cytop");
    if(!objectp(ob)){
	    ob = load_object(__DIR__"cytop");
	}
    me->move(ob);
    message_vision("$N˳���±�����������\n", me);
    return 1;
}
