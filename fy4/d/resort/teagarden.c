// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
һ���԰��̸���Ͽ�����ȴ�㹻���¡�������������Ŀ���̣�������Ҳ������
���ŷ��Ĳ��㣬԰�и��˼���ʯ�ʣ�һ��ʯ����������ЩС��Сյ��������Щ��
���ˮ����ѩɽׯ���ӵ��ǵ������˶��ˣ����ɵ��������ʳ�á�
LONG
        );
    	set("exits", ([ 
        	"east" : __DIR__"bamboo_hall",
	]) );
	set("item_desc", ([
	        "stool" : "һ��ʯ�ʡ�\n",
	        "ʯ��" : "һ��ʯ�ʡ�\n",
	        "table" : "һ��ʯ�����������Щ���Ĳ�ˮ��\n",
	        "ʯ��" : "һ��ʯ�����������Щ���Ĳ�ˮ��\n",
	        "Сյ" : "һ�����µĲ�յ��\n",
	        "teacup" : "һ�����µĲ�յ��\n",
	]) );
    	set("outdoors", "resort");
    	set("gao_amount", 70);
    	set("tea_amount", 70);
	set("coor/x",-10);
	set("coor/y",-120);
	set("coor/z",0);
	setup();
}

void init() {
	add_action("do_look", "look");
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
}

int do_look(string arg) {
	object me;
	int i, j;
	
	me = this_player();
    	i = query("gao_amount");
    	j = query("tea_amount");
    	if( !arg || arg != "table" && arg != "ʯ��" && arg !="Сյ" && arg!= "teacup" ) 
    		return 0;
    	if(arg == "table" || arg == "ʯ��") {
		if (i > 0) {
            		write("ʯ�����м��̾��µ�С����������Щ���ָ⣬���Գԣ��������ġ�\n");
		} else {
            		write("ʯ�������м���С��������ֻʣ����һЩ��������\n");
		}	
        	me->set_temp("know_gao", 1);
    	} else if (arg == "Сյ" || arg == "teacup" ) {
		if (j > 0) {
            	write("��յ��ʢ���˱��ݴ�����ð�����������������Ժȣ������룩��\n");
		} else {
            	write("��յ�ѿ��ˣ������������ڿ����е�����\n");
		}
        	me->set_temp("know_tea", 1);
	}
	return 1;
}	

int do_eat(string arg) {
	object me;
	int i;
	
	me = this_player();
    	i = query("gao_amount");
	
    	if( !arg || arg != "taosu gao" && arg != "���ָ�" && arg != "gao" ) return 0;
	if( me->is_fighting()) return notify_fail("�����ڲ��ܳԡ�\n");
    	if( i > 0 && me->query_temp("know_gao")) {
		if (me->query("food") >= me->max_food_capacity() ) {
			write("���Ѿ��Ա��ˣ�ʵ�ڳԲ����ˡ�\n");
            		message("vision", me->name() + "������ɫ�Ŀ�����ǰʣ�µĸ�㡣\n",
					environment(me), me);
			return 1;
		} else {
			if(me->is_busy()) return notify_fail("������æ�����ܳԡ�\n");
            		message_vision("$N����һ�����ָ⣬������Ʒ���š�\n", me);
			me->start_busy(2);
		}
        	add("gao_amount", -1);
        	me->add("food", 100);
    	} else if( i =0 && me->query_temp("know_gao")) {
        	write("�Ѿ�û�и���ˣ�\n");
	} else { 
		return 0;
	}
	return 1;
}

int do_drink(string arg)
{
	object me;
	int i;
	
	me=this_player();
    	i = query("tea_amount");
	
    	if(!arg || arg != "tea" && arg != "���ݴ�") return 0;
	if(me->query("water") >= me->max_water_capacity())
		return notify_fail("���ƺ������ʡ�\n");
	if(me->is_fighting()) return notify_fail("�����ڲ��ܺȡ�\n");
	if(me->is_busy()) return notify_fail("������æ�����ܺȡ�\n");
    	if (i > 0 && me->query_temp("know_tea")) {
        message_vision("$N���������յ�����ĵ�Ʒ��������\n",me);
		me->start_busy(2);
        	add("tea_amount", -1);
        	me->add("water",100);
    	} else if( i = 0 && me->query_temp("know_tea")) {
        	write("��յ�Ѿ����ˡ�\n");
        	message("vision", me->name() + "�����յ���˿���\n", environment(me), me);
	} else {
		return 0;
	}
	return 1;
}


void reset(){
	::reset();
	set("gao_amount", 70);
    	set("tea_amount", 70);
}

