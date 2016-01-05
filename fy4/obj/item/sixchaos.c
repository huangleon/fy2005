#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(BLK"�����л���"NOR, ({ "six-chaos hall" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "����ʧ���������󷨣���֪�Ǻ��˲��¡�\n");
		set("no_reset",1);
		set("no_get",1);
		set("value",100);
		set("unit","��");
    }
	::init_item();
}

void init()
{       
        object ob,carrier;


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
	object room;
	room=find_object("/d/dark_fy/fysquare");
	if (!room)
		room=load_object("/d/dark_fy/fysquare");
    if(environment(ob)!=environment()) return 0;
	if(ob==environment()) return 0;
	message_vision(HIY"\nһ��ҫ�۵Ļ�ɫ��âͻȻ����ס$N������\n\n"NOR,ob);
	ob->add_temp("block_msg/all",1);
	ob->move(room);
	ob->add_temp("block_msg/all",-1);
	tell_object(ob,HIY"��ɫ��â������ȥ�����ƺ������ƶ�����Ȼ��������\n\n"NOR);
	return 1;
}

int do_drop(string arg)
{
	object skin;
	skin=present(arg,this_player());
	if(skin!=this_object()) return 0;
    set("not_ready_yet",1);
	this_object()->move(environment(this_player()));
    set("not_ready_yet",0);
	return 1;
}
