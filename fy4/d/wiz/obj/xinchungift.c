#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIC "�´�����" NOR, ({ "gift" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("no_drop",1);
            set("no_get",1); 
            set("material", "cloth");
            set("long", "һ�������������������5��������Դ������ʹ�����쵽�����л���ô������ƺ����Դ�(open)��\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 

int do_open(string arg)
{
        object note,gift,me;
        object obj;
        int level, base,bonus,combat_exp,silver;
        me = this_player();
        bonus=1;
        if(arg != "gift" && arg != name()) return 0;
     //   if (me->query("hgift/2011/xinchun"))
       //     return notify_fail("���Ѿ����������ˣ����˲���̫̰�ģ�\n");
        if(query("opened"))
                return notify_fail(name()+"�����˴򿪹��ˣ�����Ķ��������ù��ˣ�\n");
       
        if(!random(500))
		{
                        bonus = 10;
                    
			write(HIW"���õ��˴󽱣���ϲ��ϲ��\n"NOR);
		}
       
      level = F_LEVEL->get_level(me->query("combat_exp"));
      base =  2*REWARD_D->quest_reward(level);
combat_exp = base * bonus * (100 + QUESTS_D->query_holiday())/100;
if (me->query("env/ability") 
			&& F_LEVEL->get_level(me->query("combat_exp"))>=80
			&& me->query("saved_quest")/60/100 < me->query("learned_ability") + 6) 
		{
			me->add("saved_quest",2*60*bonus);
			if (QUESTS_D->query_holiday())
				me->add("saved_quest",2*60*bonus*QUESTS_D->query_holiday()/100);
		}	
else {
			
			if (me->query("combat_exp")>= 10000000) {
				me->add("extra_exp", combat_exp);
			}
			
			if (me->query("combat_exp") < 10000000)
				me->add("combat_exp", combat_exp);
		
			if (me->query("combat_exp")>= 10000000)
				me->set("combat_exp",10000000);
		}
 silver = 30 * bonus * (100 + QUESTS_D->query_holiday())/100 ;
  me->add("deposit",silver*100);
	tell_object(me,WHT"\n��ϲ���"+name()+"������õ���:\n" + chinese_number(silver) + "�����ӣ�\n"+chinese_number(combat_exp)+"�㾭�飡\n"NOR);
       
	
        set("opened",1);
       // me->set("hgift/2011/xinchun",1);
        destruct(this_object());
        return 1;
}
