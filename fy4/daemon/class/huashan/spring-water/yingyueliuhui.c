// Silencer@fengyun	June.2005
//	���ؼ������������ڣģ�ĵ�Mirror_Image,�ܹ���ʱ��50%������ȥ�˺�������Ч����
//	starts from 3@100, then 5@120, ��ֹ��ս���У������

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int stone_done(object me, object caster);
int perform(object me, object target)
{
        int skill, num;
		mapping buff;	
		string msg;
	
        if(me->query("class")!="huashan")
    		return notify_fail("ֻ�л�ɽ���Ӳ���ʹ����ӳ�����ԡ�\n");

    	if( userp(me) && (string)me->query("gender") != "Ů��" )
        	return notify_fail("��һ�������˾�Ȼѧ��������ŤŤ����Ĺ���Ҳ����˼�ã���\n");
        	
        skill = me->query_skill("spring-water",1);
		if(skill < 120 || me->query_skill("hanmei-force",1)<200) 
			return notify_fail("ӳ��������Ҫ120���Ĵ�ˮ������200���ĺ�÷�ķ���\n");
        
        if (me->query_skill_mapped("force")!="hanmei-force")
        	return notify_fail("ӳ������Ψ����Ϻ�÷�ķ�����Ч��\n");
        
        if(!target) target = me;
        if( target != me ) 
        	return notify_fail("��ֻ�ܽ�ӳ�����������Լ������ϡ�\n");
        
        if( ANNIE_D->check_buff(me,"ironup")|| ANNIE_D->check_buff(me,"hs_yylh"))
        	return notify_fail("���Ѿ���ʩչ���ƵĻ������ˡ�\n");
        
        if (userp(me) && me->is_fighting())
			return notify_fail("ӳ�������޷���ս����ʹ�á�\n");	
		
        if( me->query("force") < 150 )     
        	return	notify_fail("ӳ��������Ҫ150���������\n");
		if (userp(me))	me->add("force", -150);
		
    	msg = HIC
"$N��ü���ף�����ӳ�����ԡ���������������ӳ�Ǻӣ�����ҡҷ��\n"NOR;
    	msg += WHT
"������$N����Ӱ�ƺ�������������������Ʈ��������\n" NOR;

        num = 3 + (skill - 100)/10;
		if (num >=5 ) num = 5;
	
		me->set_temp("pfm/hs_yingyueliuhui",num);
		buff =
			([
				"caster":me,
				"who":	me,
				"type2": "ironup",
				"type": "hs_yylh",
				"att": "bless",
				"name": "��ˮ������ӳ������",
				"time":    180,
				"buff_msg":msg,
				"warn_msg":"",
				"finish_function": (: stone_done :),
			]);
		
		ANNIE_D->buffup(buff);
	    return 1;
}


int stone_done(object me, object caster){
	me->delete_temp("pfm/hs_yingyueliuhui");
	return 1;
}


