// L150: �ۺ�����ˮ�ɱ�����÷��̶�������۳ɺ�����ÿ15���ӵõ�һƬ��heal self 2��
// ice ʵ��ֻ�ǰ��裬mark��ʹ��������

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target)
{
    string msg,name;
	object ice;
	int duration, amount, dorm, skill, num;
	
	if(me->query("class")!="legend" && userp(me))
		return notify_fail("ֻ����ѩɽׯ�ĵմ����Ӳ��ܹ�ʹ�þۺ�����\n");

 	skill = me->query_skill("qidaoforce",1);
 	dorm = me->query_skill("dormancy",1);
 	
 	if( skill <150)
		return notify_fail("���ۺ�������Ҫ150��������ķ���\n");
 	
 	target=me;
 	
 	/*
 	set("resource/water", 1);
	set("liquid/container", "÷��̶");
	set("liquid/name","÷��̶ˮ");
 	*/
 	 	
 	if (!environment(me)->query("resource/water"))
 		return notify_fail("���ۺ�������Ҫ��ˮԴ�Է���ʩչ��\n");
 	
 	if (!stringp(name=environment(me)->query("liquid/name")))
 		name = "ˮ��";
 	 	
 	if (me->is_fighting())
 		return notify_fail("ս���в���ʩչ���ķ���\n");	
 		
 	duration = me->query("timer/legend_juhan")-time() + 900;
    if (duration>0)
       	return notify_fail("����Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ��ܹ��ٴ�ʹ�þۺ�����\n");
 	
 	msg = WHT"$N��������������ɢ��˿˿������"+ name + "�������ģ�˲������ɱ���\n"NOR;
    
    amount = 1000;
    num = 2;
    
    if (dorm >= 270) {amount = 3000; num = 3;}
	else if (dorm > 220) {amount = 2000; num = 2; }  
    	         
   		seteuid(getuid());
        ice = new("/obj/specials/legend/ice");
        
        if (!ice->move(me)) {
        	destruct(ice);
        	return 1;
        }
        
        ice->set("juhan_owner",me);
        ice->set("amount",amount);
        me->set("timer/legend_juhan",time());
        me->set("marks/legend_juhan",num);
        message_vision(msg, me);
	
	me->perform_busy(1);
	       
	return 1;       
}
