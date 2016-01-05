
inherit ROOM;

string flower();
void create()
{
        set("short", "����̨");
        set("long", @LONG
�����̨ȴ����ɽ������ɽ������һ��ƽ�أ����ܾ޴�ĹŰ�������ա�ƽ��
��ԭ�����Ͼ������ķ��Ѿã�����ֻʣ�²�ǽ���ߣ��Ӳ�������ֻ��һ����÷��
����֦Ҷï�ܣ�ÿ���꺮������ŭ�ţ����ǵ��������ܣ���Ʈʮ�
LONG
        );
    set("exits", ([ 
  		"northup" : __DIR__"chaoyang",
	    "southwest" : __DIR__"shanlu",
	]));
  	set("objects", ([
  		__DIR__"obj/wall" : 1,	
  		__DIR__"npc/girl1" : 1,
  	])); 
    set("item_desc", ([
    	"��÷" : (: flower :),
    	"tree" : (: flower :), 
    ]));
    set("flower_amount", 5);
    set("outdoors", "huashan");

	set("coor/x",-4);
	set("coor/y",-56);
	set("coor/z",30);
	setup();
}

string flower(){
	object me;
	int i, j;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 4) {
		tell_object(me, "��÷����ŭ�ţ���ɫ����÷�������ڰ�ѩ�������������ţ������г�����÷�����㡣\n");
		add_action("do_pick", "pick");
	} else {
		tell_object(me, "��÷��֦Ҷï�ܡ�\n");
	}		
	return "";
}

int do_pick(string arg){
	object me, flower;
	me = this_player();
	if(!arg || (arg != "flower" && arg != "��÷")) {
		return 0;
	}
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("������æ��\n");
	}
	if(query("flower_amount") > 0) {
		message_vision("$N̽��ժ��һ֦��÷����\n", me);	
		flower = new(__DIR__"obj/wintersweet");
		flower->move(me);
		add("flower_amount", -1);
	} else {
		return notify_fail("��÷û���ˡ�\n");
	}
	return 1;
}

void reset(){
	::reset();
	set("flower_amount", 5);
}
