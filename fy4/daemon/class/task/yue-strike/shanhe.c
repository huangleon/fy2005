// Silencer @ FY4 workgroup. Aug.2004
//	ɽ��ͬ�٣�ÿһ�ж��Ƿ���������dodge
// ��˼˵����֮�󣬾����࣬������ų�����ʵ��ɱ����ʡ�����ȡ��ı�׳������
//	Can't stop ppl unwield all .....
//	Can make it so he won't dodge, only parry counter... thinking.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        mapping buff;
        
	extra = me->query_skill("yue-strike", 1);
        if ( extra < 150) 
        	return notify_fail("��ɽ��ͬ�١���Ҫ160����С��ɽ�ƣ�\n");
        
        msg = HIY  "$N���쳤̾��ʹ����С��ɽ�Ƶġ�ɽ��ͬ�١���һ�ɺ�Ȼ����ֱ��������\n" NOR;
        
        buff =
		([
			"caster": me,
			"who":   me,
			"type": "riposte",
			"att":	"bless",
			"name":	"С��ɽ�ơ�ɽ��ͬ��",
			"buff1":"pfm/yue-strike/shts",
			"buff1_c":1,
			"time":  60 ,
			"buff_msg": msg,
		]);          
        
        ANNIE_D->buffup(buff);
                
        return 1;
}
