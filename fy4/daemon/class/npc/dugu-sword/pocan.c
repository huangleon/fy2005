#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg,sk;
 object weapon; 
 int skill,ap,dp,tf;

 if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���Ʋ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 skill = (int)me->query_skill("dugu-sword",1);
 if( skill < 200 && userp(me))
  return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ʋ�ʽ����\n");
  if( me->query("force") < 1000 )
  return notify_fail("��������������޷����á��Ʋ�ʽ����\n");
 msg = HIW "$N�����򣬶��¾Ž����Ʋ�ʽ���Ծ���֮����$n������ \n";
  if(userp(me)) me->delete("force");
 ap =  (int) me->query("combat_exp")* skill/10;
 dp = (int) target->query("combat_exp");
 if(random(ap+dp) > dp) {
  if(userp(target)){
   weapon = target->query_temp("weapon");
   if(!weapon) sk= "unarmed";
   else sk= weapon->query("skill_type");
   tf = target->query_skill(sk,1);
   if(tf>=2)
   target->set_skill(sk,tf-1);  
  }
 msg += "$n��ʧɫ���ľ����������Ѿ�̫���ˣ�\n" NOR;
 target->start_busy(2);
 }else {
 msg += "����$n������$N�Ľ�·���͵�һ����ʮ���Ǳ��Ķ����һ�С�\n"NOR;
 me->start_busy(4);
 }
 message_vision(msg, me, target);
 return 1;
}
