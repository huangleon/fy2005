// Silencer@fengyun	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;

string *event1_msg=	({
	"�����಻�࣬�o���಻�࣬�x���಻�࣬��������ࡣ\n",
	"������δ�����ƺ���������������������������������\n",
	"�����ԟo霣�ס̎���o霣���������գ���������ա�\n",
	"�Пoһ�r�o���x�o�����o�����x�o���У��Єt�����o��\n",
	"�����T���գ��Ǆt���������ŷ��գ�һ�н��`ʧ��\n",
	"���ԟo�ǿգ��o����������δ�����ИI�����������ߡ�\n",
	"�������_�ۣ���������������^�ѳ������Z���Ԝ硣\n",
	"�o�����������Q�ĳ�һ�����������ˣ��t��Ҋ������\n",
});
	
int main(object me)
{
	int i, skill, amount;

	me = this_player();
	if (me->query("class")!="lama" && me->query("class")!= "shaolin"
		&& me->query("class")!= "bonze")
		return notify_fail("���Ǻ�����ʲô����\n");
	
	// usually it should be around 200 - 400
	amount = me->query_skill("zen",1)
			+ me->query_skill("lamaism",1)
			+ me->query_skill("buddhism",1);
		
	if (amount < 150)
		return notify_fail("��Ծ��ĵ��˽�̫ǳ���ˡ�������\n");
		
	if( !me->is_fighting() )
		return notify_fail("�о�ֻ����ս����ʹ�á�\n");
	
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	
/*	if( ANNIE_D->check_buff(me,"forceshield")) 
    	return notify_fail("������һ��������ô�����\n");*/
       		
	if (me->query_temp("timer/chanting"))
		return notify_fail("���Ѿ����о��ˡ�\n");

	if( userp(me) && me->query("sen") < 150 )
		return notify_fail("�о���Ҫ�ķ�150������\n");
	if (userp(me))	me->receive_damage("sen", 150);
			
	me->start_busy(2);
	amount = amount/2;
	
	message_vision(HIR"$Nһ�ֳַ��飬һ����ָ�ᴥ�������ӡ�����̷�ţ�\n" NOR, me);
    me->set_temp("timer/chanting",1);
	call_out("dot",6,me,7,0,amount);  
	return 1;
}

void dot (object me, int total, int count, int amount)
{
	int num, my_exp, his_exp, i, enhance;
	object *ob;
	
	if (!me)	return;
		
	ob = me->query_enemy();
	if (!ob || sizeof(ob)<1) {
		message_vision(WHT"$N����˵�����������ӷ�ʩ���������ˣ���\n"NOR,me);
		me->delete_temp("timer/chanting");
		return;
	}

	message_vision(WHT"$N�����"+event1_msg[count]+"\n"NOR,me);
	enhance = amount> 100 ? amount: 100;
	
    for(i=0; i<sizeof(ob); i++)   {
       	if (!living(ob[i])) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (environment(ob[i]) != environment(me)) continue;

		if (COMBAT_D->do_busy_attack(me, ob[i], "chant", "step", enhance, 10))
		{
			// for normal SL/DZ/XG, it's 100 + random(100);
			num = amount + random(amount);
			num = COMBAT_D->magic_modifier(me, ob[i], "sen", num);
			ob[i]->receive_wound("sen",num,me);	// Wound is not effective on NPCs
			
			// Every 3 turns 50% chance (same exp) it will add 400 + random(400) hate
			if (!userp(ob[i]))
				ob[i]->add_hate(me, num*3);		// chant will add *4 hate.
			
			tell_object(ob[i],RED"�����ͷʹ���ѣ��������˹�ȥ��\n"NOR);
			COMBAT_D->win_lose_check(me,ob[i],num);			
    		}
    	}
    	
	count++;
	if (count<= total) call_out("dot",6,me,total,count, amount);
		else 
		{
			message_vision(WHT"$N����˵�����������ӷ�ʩ���������ˣ���\n"NOR,me);
			me->delete_temp("timer/chanting");
		}
	return ;
}


int help(object me)
{
    write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : chant[0m
[0;1;37m����������������������������������������������������������������[0m
��Ƿ��������֡��˹������Ѷ��еļ��ܣ�
ʹ�õ�����Ϊ���ڷ𷨡���˷𾭡������ĵȼ�֮�͸��ڣ�������
�������ž��ĵ���ϰԽ����Ч����Խ���ԡ�

���ս����������Ч��

����������Χ���˵���������ֵ��ɳ������˺�
������������Χ���˵�ע��������Ի���Ҳ��������˭�룿

[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}



