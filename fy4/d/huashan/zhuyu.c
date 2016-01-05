
inherit ROOM;
int b_shoot();
void create()
{
        set("short", "����");
        set("long", @LONG
�˴������������ȴ��̣�������Ȼ������ɽ�紵����ֻ��ɳɳ��Ҷ������
�����١��������߷�����ӣ�ɽ����������������ݺᣬ��ʯ������ɽ��С·��
�����ۣ�·�������������ҡҷ��һƬ������
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"xiaojing",
  		"westup" : __DIR__"changpu",
		"eastup" : __DIR__"ziwei",
	]));
   	set("shoots_amount", 3);
   	set("bamboo_amount", 3);
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",10);
	set("coor/z",-30);
	setup();
}

void init(){
	if(NATURE_D->get_season() == 1 && NATURE_D->get_weather() == "С��") {
		tell_object(this_player(), "���У�ֻ��������֮�в��ϴ��������ࣵ�������\n");
	}
	add_action("do_search", "search");
	add_action("do_pick", "pick");
}
 
int do_pick(string arg)
{
    object bamboo;
    if ( !arg && arg != "bamboo" && arg != "����" && arg != "zhuzi")
            return notify_fail("��Ҫ��ʲô��\n");
    if((int) query("picked") <= 2)
    {
            write("������һ����������ӣ�С�ĵķ��ڻ��\n");
            bamboo = new("/d/taoyuan/obj/bamboo");
            bamboo->move(this_player());
            add("picked",1);
            return 1;
    }
    else
    write("�����Ѿ������۹��ˣ���\n");
    return 1;
}

int do_search(){
	message_vision("$N��ϸ�������ֵ���Ѱ�ҡ�\n", this_player());
	if(NATURE_D->get_season() == 1 && query("shoots_amount") >= 0) {
		tell_object(this_player(), "�㷢��һ�����۵�����ոչ������档���԰����ٳ�����\n");
		this_player()->set_temp("marks/found_shoot", 1);
	} else {
		tell_object(this_player(), "��ʲôҲû�з��֡�\n");
	}
	return 1;
}

int dig_notify() {
	object me, item;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(me->is_busy()) { 
	    write("����������æ��\n");
	    return 1;
	}
	if(me->is_fighting()) return 0;
	if(NATURE_D->get_season() != 1 || !me->query_temp("marks/found_shoot")) {
	    message_vision("$N����������һ�٣������������Ƶ������ʲôҲû�з��֡�\n", me);
	} else {
		if (query("shoots_amount") >= 0) {
    		message_vision("$N����������һ�١�\n", me);
        	message_vision("һ�����۵�����¶�˳�����\n", me);
        	me->delete_temp("marks/found_shoot");
        	item = new(__DIR__"obj/bshoot");
        	if(objectp(item)) {
        		item->move(this_object());
        		add("shoots_amount", -1);
			}
		}
	}
	me->start_busy(1);
}

void reset(){
	::reset();
	set("shoots_amount", 3);
	delete("picked");
}
