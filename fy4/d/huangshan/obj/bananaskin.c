#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�㽶Ƥ", ({ "banana skin", "xiang jiao pi" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ�ź������㽶Ƥ���ƺ��кܶ�㡣�㽶Ƥ����ڻ���\n");
        set("unit", "��"); 
        set("value", 0);
    }
	::init_item();
}
void init()
{       
        object ob,carrier;

        ::init();
        carrier=environment();
       if (query("not_ready_yet")) return;
        if( interactive(ob = this_player()) )
        
         {
                remove_call_out("sliding");
                call_out("sliding", 1, ob);
        }

        add_action("do_drop","drop");
        
}

int sliding(object ob)
{
        if(environment(ob)!=environment()) return 0;
	if(ob==environment()) return 0;
	message_vision(HIY"$N��Ȼ������Щ���ס������ƺ�������ʲô�����Ƶġ�\n"NOR,ob);
	message_vision(HIY"$Nһ���ӵ��˸�����ࡣ����������ġ�����\n"NOR,ob);
	ob->start_busy(2);
	ob->receive_damage("sen", 100);
	return 1;
}

int do_drop(string arg)
{
	object skin;
	skin=present(arg,this_player());
	if(skin!=this_object()) return 0;
	tell_object(this_player(),"����˲�ע�⣬͵͵�Ľ��㽶Ƥ�����˵��ϡ�����\n");
	message("vision",this_player()->query("name")+"�������Ľ�ʲô���������˵��ϡ�\n",environment(this_player()),this_player());
    set("not_ready_yet",1);
	this_object()->move(environment(this_player()));
    set("not_ready_yet",0);
	return 1;
}
