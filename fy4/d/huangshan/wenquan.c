// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
��ɽ��Ȫ�ų���Ȫ�������ơ����Ʒ��²�̫������ʩ¯���Գ�������������ҽ
ҩ�����������¡���Ϊ�����ӿ����ɫȪˮ����Ϊ��ɰ�������ֳ���ɰȪ����Ϊ
��ů��ʪ���к��µ�������������һЩ�ȴ�������㽶��������������������
���ܺá���Ȫ���ϱ��Ǵȹ�󣬱���ԶԶ�ɼ�����ͤ��
LONG
        );
    set("exits", ([ 
  		"westup" : __DIR__"taohua", 
  		"northup" : __DIR__"guanpu",
  		"eastdown" : __DIR__"shanmen", 
	]) );
	
	set("objects", ([
    	__DIR__"obj/tangquan" : 1,
    ]) );
    
    set("item_desc", ([
    	"������" : "�����û������ô�ߴ�������������Ͽ�ȥ�������Ĵ�������˵
Ҳ�ж�ʮ�� ��Ҳ���������ҡһҡ��SHAKE����������\n",
    	"durian tree" : "�����û������ô�ߴ�������������Ͽ�ȥ�������Ĵ�������˵
Ҳ�ж�ʮ�� ��Ҳ���������ҡһҡ��SHAKE����������\n",
		"�㽶��" : "һ�Գ����쳣ï�ܵ��㽶���������ߡ�����һ�����㽶�ֻ����ִ�
���г��ϵĿ����õöࡣ\n",
		"banana tree" : "һ�Գ����쳣ï�ܵ��㽶���������ߡ�����һ�����㽶�ֻ����ִ�
���г��ϵĿ����õöࡣ\n",
    ]) );
    
    set("banana_amount", 3);
    set("durian_amount", 3);
    set("outdoors", "huangshan");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void init() 
{
	add_action("do_shake", "shake");
	add_action("do_pick", "pick");
}

int do_pick(string arg)
{
   	object me, banana;
	int i, luck;
	
	i = NATURE_D->get_season();	
   	me = this_player(); 
   	luck = me->query_kar();
   	if(!arg || arg != "banana" && arg != "�㽶") return 0;	
	if( i==1 || i == 2){  
   		if ((int)query ("banana_amount") >= 1)
   		{
   			if (random(luck) > 15) {
				banana = new(__DIR__"obj/gbanana");
      			banana->move(me);
      		} else {
      			banana = new(__DIR__"obj/banana");
      			banana->move(me);
      		}
      		add("banana_amount", -1);
      		message_vision("$N����ժ��һ���ֻ����ִ���㽶������\n", me);
   		}
   		else { 
      		write ("�㽶����ժ���������� \n");
   		}
   	} else {
   		message_vision("$NΧ���㽶��ת��һȦ��\n", me);
   		write("��ʲô��û���ҵ���\n");
   	}	
   	return 1;
}

int do_shake(string arg)
{
	object me, durian;
	int i, j, season;
	
	me = this_player();
   	i = me->query_str();
	season = NATURE_D->get_season();	
   	if(!arg || arg != "������" && arg != "durian tree" && arg != "tree") return 0;	
	if(me->is_busy()) {
		write("��������æ��\n");
   	    return 1;
   	}
   	if( i > 20 ) {
		message_vision("$N�þ�ȫ�����������ڰ�������ҡ�ðڶ�������\n", me);
		me->start_busy(3);
		if(random(i) > 5 && (int)query("durian_amount") >= 1 && (season == 2 || season == 4)) {
			remove_call_out("durian_fall");
			call_out("durian_fall", 1, me); 
		} 
		return 1;
	} else {
		message_vision("������̫���ˣ�$N����ҡ��������\n", me);
	}
	return 1;
}

void durian_fall(object me)
{
	object durian;
	int luck;
	
	luck = me->query_kar();
	if(random(luck) < 5 ) {
		message_vision(RED"$N�۵�һƨ�����ڵ��ϡ���Ȼ��һ�Ŵ�������Х�Ŵ��������£�\n"NOR, me);
		message_vision(RED"$N�������ܣ��˵�һ��������������$N��ͷ�ϣ�����\n"NOR, me); 
		remove_call_out("see_star");
		call_out("see_star", 2, me);
	} else {
		message_vision(HIY"һ�Ŵ�������Х�Ŵ��������£�ž��һ������$N���ԡ�\n"NOR, me);
	}
	add("durian_amount", -1);
	if(random(luck) > 10) {
		durian = new(__DIR__"obj/gdurian");
		durian->move(this_object());	
	} else {
		durian = new(__DIR__"obj/durian");
		durian->move(this_object());
	}
}

void see_star(object me)
{
	int i;
	
	i = me->query_int();
	tell_object(me, HIC"����ǰͻȻ���ֺö����ǡ�������\n"NOR);
	tell_object(me, HIW"�����У��ƺ���������չʾ��ϵ���ݱ�... ���Ȼ�е�����\n"NOR);
	message("vison", me->name() + "ɵ�Ǻǵ����ſ�ˮ ~~\n", environment(me), me);
	me->apply_condition("idiot", 1, this_object()); 
}
