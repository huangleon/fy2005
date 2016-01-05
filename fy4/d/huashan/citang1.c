#include <ansi.h>
inherit ROOM;
string tree();
string citang();
void create()
{
        set("short", "����ǰԺ");
        set("long", @LONG
�ƹ���ǽ��һ�����ã����õ�Ժ���һ���Ű������ڵأ���Ŀ��ǽ�ϱڡ�Ժ
��һ�ù������ƺ��кܶ���ѻ�ĳ�Ѩ����ʱ������ѻ�����ɡ��Ľ������˷��ꡣ��
��ûϥ���ڷ��з�����ɪ��������Ժ����һ�����õ����á�
LONG
        );
    	set("exits", ([ 
		"west" : __DIR__"hpath2",
		"east" : __DIR__"citang2",
	]));
	set("objects", ([
		__DIR__"obj/huangcao" : 1,
		__DIR__"obj/door" : 1,
	]) );   
	set("item_desc", ([
		"tree" : (: tree :),
		"����" : (: tree :),
		"��" : (: tree :),
		"����" : (: citang :),
		"citang" : (: citang :),
	]) );
	set("have_spear", 1);
    	set("outdoors", "huashan");
	set("coor/x",-7);
	set("coor/y",15);
	set("coor/z",-10);

	setup();
}

string citang(){
	object me;
	string weather;
	int i;
	i = NATURE_D->get_season();
	me = this_player();
	if(i){
		weather = NATURE_D->get_weather();
	    if((weather == "��" || weather == "����") && query("have_spear")) 
        {
			tell_object(me, "��ǽһ�ǵ����ӱ���ˮ�ݵ���Щ���䣨������� ������򣩡�\n");
			add_action("do_search", "search");
			return "";
		} 
		if (!query("have_spear") && !present("corner", this_object())) {
			tell_object(me, "��ǽһ�ǵ������Ѿ��ƿ��������ƺ����������˶�����\n");
		} else {
			tell_object(me, "��ǽһ�ǵ����ӱ���ˮ�ݵ���Щ���䡣\n");
		}
		
	} else {
		tell_object(me, "һ���ƾɵļ�춵��������á�\n");
	}
	return "";
}

int reset(){
	::reset();
	set("have_spear",1);
}


int do_search(string arg){
	object me, corner, spear;
	me = this_player();
	if(!arg || (arg != "corner" && arg != "����")){
		return notify_fail("��Ҫ��Ѱ���\n");
	}
	message_vision("$N�����������ӣ���ž����һ����һƬ��ľ����������\n", me); 
	if (!query("have_spear"))	return 1;		
	tell_object(me, "�������ƺ���һ��������Ķ�����\n"); 
	corner = new(__DIR__"obj/corner");
	spear = new(__DIR__"obj/zhangspear");
	if(objectp(corner)){
		corner->move(this_object());
	}
	if(objectp(spear)){
		spear->move(corner);
	}
	set("have_spear", 0);
	remove_action("do_search","search");
	return 1;
}

string tree(){
	object me;
	int i, j, num = 1+random(10);
	me = this_player();
	i = NATURE_D->get_season();
	message("vision", me->name() + "��ͷ�����Ͽ��˿���\n", environment(me), me);
	if(i == 4) {
		tell_object(me, "��ͺͺ���������м����޴�����ѡ�\n");
	} else {
		tell_object(me, "֦Ҷï�ܣ�����ѿ�������Ķ�����\n");
		j = me->query("kar");
		if(random(j) > 15 && i != 3 && NATURE_D->is_day_time()){
			message_vision(YEL"��Ȼ��һ��������¸պ��ҵ�$N��ͷ�ϡ�\n"NOR, me);
			if (!me->query("����B/��ɽ_���")) {
				me->set("����B/��ɽ_���", num);
				log_file("riddle/FATE_LOG",
				sprintf("%s(%s) �õ�����B/��ɽ_��� "+num+"�� %s \n",
					me->name(1), geteuid(me), ctime(time()) ));
			}
		}
	}		
	return "";
}
