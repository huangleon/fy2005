#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"��ڵ�ͭ��"NOR, ({ "needle pipe"}) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��СС�ĺ�ɫԲͲ��\n"	);
                set("material", "gold");
                
        }

        ::init_item();

}
void init()
{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
	object ob;
	object me;
	int dp;
	int damage;
	
	if (!arg) return 
		notify_fail("��Ҫ��˭��\n");
    	
    	if (query("used")) 
    		return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
	
	me=this_player();
    	if (userp(me))
    		return notify_fail(this_object()->name()+"�Ѿ������ˡ�\n");
    	    	
    	ob=present(arg,environment(me));
    	if (!objectp(ob) || !living(ob)) 
    		return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
      		
    	message_vision("ţë����������$N���ϡ�\n",ob);
    	damage = 2000;
    	ob->receive_wound("kee",damage,me);    
    	ob->receive_wound("gin",damage,me);    
    	ob->receive_wound("sen",damage,me);    
    	COMBAT_D->report_status(ob);                                             	
    	return 1;
}
