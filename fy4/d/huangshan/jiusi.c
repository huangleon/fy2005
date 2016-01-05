// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
int do_put(object me, object obj);
void create()
{
        set("short", "С����");
        set("long", @LONG
���Ŵ����ʯ���ŷ���һ����ª��С���������Ӵ�ɵļ��ӣ�é��������һ��
ϸ�������һ��С�죬�����Ƕ���ľ��֣�������һ��ľ�䡣���°��ż��ż�ª��
���ʺ�ľ����������Ϣ�������Դ��������һ����ף�����������Ʈ������ֵ�
������û���˿��ܣ��ο�ȡʳ��󣬶����Զ���ľ���зţ�����磩Ǯ��      
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"shanmen",
	]) );
	set("item_desc", ([
		"stool" : "�򵥵�Сľͷ����ʡ�\n",
		"����" : "�򵥵�Сľͷ����ʡ�\n",
		"ľ��" : "ľ������һ�����ڣ�����Էţ�����磩Ǯ��ȥ��\n",
		"box" : "ľ������һ�����ڣ�����Էţ�����磩Ǯ��ȥ��\n",
	]) );
    set("outdoors", "huangshan");
	set("mantou_amount", 50);
	set("jiu_amount", 70);
	set("coor/x",0);
	set("coor/y",5);
	set("coor/z",0);
	setup();
}

void init() {
	add_action("do_look", "look");
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
	add_action("do_tou", "fang");
}

int do_tou(string arg){
	string item;
	object me, obj, obj2, *inv;
	int amount;
	me = this_player();
	
	if(!arg) {
		return notify_fail("��ҪͶʲô��\n");
	}
	if(me->is_fighting() || me->is_busy()){
		return notify_fail("������æ��\n");
	}
	sscanf(arg, "%s", item);

    if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) ) {
 			return notify_fail("������û������������\n");
   		}
  		if(obj->query("money_id") != "silver" && obj->query("money_id") != "gold" 
				&& obj->query("money_id") != "coin" ){
     		return notify_fail( "����ͶǮ�ɣ�\n");
   		}
        if( amount < 1 )
                return notify_fail("����������������һ����\n");
        if( amount > obj->query_amount() )
                return notify_fail("��û��������" + obj->name() + "��\n");
        else if( amount == (int)obj->query_amount() )
                return do_put(me, obj);
        else {
                obj->set_amount( (int)obj->query_amount() - amount );
                obj2 = new(base_name(obj));
                obj2->set_amount(amount);
                return do_put(me, obj2);
        }
    }
	if( !objectp(obj = present(item, me)) ) {
    	return notify_fail("������û������������\n");
    }
    if(obj->query("money_id") != "silver" && obj->query("money_id") != "gold" 
		&& obj->query("money_id") != "coin" ){
        return notify_fail( "����ͶǮ�ɣ�\n");
    }
   return do_put(me, obj);
}

int do_put(object me, object obj){
    int i, j, value;
    message_vision("$N��" + obj->name() + "Ͷ����ľ�䡣\n", me);
    i = obj->query("base_value");
    j = obj->query_amount();
    value = i*j;
    if(value < 10) {
    	message("vision", me->name()+"���˲�ע���������˼���ͭ���ȥ��\n", environment(me), me);
    }
    if(value > 20000 && !me->query("marks/����")) {
    	me->set("marks/����", 1);
    }	
    destruct(obj);
    return 1;
}
	
int do_look(string arg) {
	object me;
	int i, j;
	
	me = this_player();
	i = query("mantou_amount");
	j = query("jiu_amount");
	if( !arg || arg != "table" && arg != "ľ��" && arg != "dagang" 
&& arg != "�Ƹ�" && arg != "���") return 0;
	if(arg == "table" || arg == "ľ��") {
		if (i > 0) {
			write("����������һ������������ЩС������ͷ�������ǿ��Գԣ������������������ġ�\n");
		} else {
			write("����������һ����������ֻʣ����һЩ��ͷ����\n");
		}	
		me->set_temp("know_mantou", 1);
	} else if (arg == "dagang" || arg == "�Ƹ�" || arg == "���") {
		if (j > 0) {
			write("�Ƹ���װ��Щ�׾ƣ��Ա߹��˸���Ҩ�������˱ǡ�����Ժȣ������롡�����壩��\n");
		} else {
			write("�Ƹ��Ѿ����ˣ�������Ȼ�����ŵ�ŨŨ�þ��㡣\n");
		}
		me->set_temp("know_jiu", 1);
	}
	return 1;
}	

int do_eat(string arg) {
	object me;
	int i;
	
	me = this_player();
	i = query("mantou_amount");
	
	if( !arg || arg != "man tou" && arg != "��ͷ" && arg != "mantou" ) return 0;
	if( me->is_fighting()) return notify_fail("�����ڲ��ܳԡ�\n");
	if( i > 0 && me->query_temp("know_mantou")) {
		if (me->query("food") >= me->max_food_capacity() ) {
			write("���Ѿ��Ա��ˣ�ʵ�ڳԲ����ˡ�\n");
			message("vision", me->name() + "������ɫ�Ŀ�����ǰ�����ϵ���ͷ��\n",
					environment(me), me);
			return 1;
		} else {
			if(me->is_busy()) return notify_fail("������æ�����ܳԡ�\n");
			message_vision("$N����һ��С��ͷ���������̵��˶����\n", me);
			me->start_busy(2);
		}
		add("mantou_amount", -1);
		me->add("food", 20);
	} else if( i =0 && me->query_temp("know_mantou")) {
		write("�Ѿ�û����ͷ�ˣ�\n");
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
	i = query("jiu_amount");
	
	if(!arg || arg != "wine" && arg != "�׾�") return 0;
	if(me->query("water") >= me->max_water_capacity())
			return notify_fail("���ƺ������ʡ�\n");
	if(me->is_fighting()) return notify_fail("�����ڲ��ܺȡ�\n");
	if(me->is_busy()) return notify_fail("������æ�����ܺȡ�\n");
	if (i > 0 && me->query_temp("know_jiu")) {
		message_vision("$N������Ҩ�����������ھƸ���Ҩ��һ���׾ƣ����˹��˹�����ȥ��\n",me);
		me->start_busy(2);
		add("jiu_amount", -1);
		me->add("water",10);
		me->apply_condition("drunk", me->query_condition("drunk") + 4 + random(6));
	} else if( i = 0 && me->query_temp("know_jiu")) {
		write("�Ƹ��Ѿ����ˡ�\n");
		message("vision", me->name() + "̽ͷ���Ƹ��￴�˿���\n", environment(me), me);
	} else {
		return 0;
	}
	return 1;
}
