
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int havenothingon(object ob)
{  
        object *inv;
        inv = all_inventory(ob);
        if (sizeof(inv)==0) 
                return 1;
        else
                return 0;
}
int perform(object me, object target)
{
    object *tar;
    object obj,ob;
    int i,size;
		
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����ҹ�¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	ob = target;

        tar = all_inventory(ob);
        size=sizeof(tar);
        
        if(!havenothingon(ob))
        {
			i=random(size);
			obj=tar[i];
			if(!(int)obj->query("no_get") && !(int)obj->query("no_drop"))
			{
				if (!obj->move(me))
					obj->move(environment(me));   
				message("vision",HIB"һ��΢�������������ƺ�����"+me->name()+"��Ӱ���ڷ�������һ�Ρ�\n", environment(me),me);
				message("vision",HIB"�������ۣ�ȴ����"+me->name()+"��Ȼ����ԭ�أ��ƺ�ʲô��û�з�����\n"NOR, environment(me),me);
				tell_object(me, "������ˣ�\n");
				tell_object(ob, "��о�����һ�ᣬ�ƺ�����ʲô����������\n");
				return 1;
			}
        }
        else
        {
			return notify_fail("�����ҹ�¡�û��ʹ�õı�Ҫ��\n");
        }

	return 1;
}


