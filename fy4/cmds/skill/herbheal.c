/*	Herb heal by silencer@fy4.

compared it with normal healing pills
1. 2 silver ��Ƥ��ҩ 					40 sen
2. 3 silver ���ϰ�ҩ������裬������ 			100kee/50sen/50gin
3. 10 silver ����/�˲�/¹��  				300kee/200gin/200sen
4. 60 silver	��ɫ��绨/��Ҷ��β��/ѩ֥  		1500kee/1000sen/1000gin
5. 200 silver	�Ż���¶��/�����ܵ���/���令�ĵ�	5000kee/2500sen/2500gin


all can be collected by knight player.

L 100 herb, can be bought
type 1: herb_a: "������","�Ⱦ���","��Ǯ��","�ض���","���Ĳ�", 	
	Level 100, base_value effect 500(2s)-1000(4s)-1500(6s)-2000(8s)-2500(10s) kee
type 2: herb_b: " "ľ��","��ľ��","̴��",			
	Level 100, base_value effect 500(2s)-1000(4s)-1500(6s) sen/gin

L Level 150 herb random_drop 
type 1: herb_c: "�����Ĳ�","�Ϻӳ�","��Ҷ��צ��",  
	random(3) drop, knight 3000, 3500, 4000 kee
type 5: herb_d: "�׻��߲�","���ĺ���","���Ҷ",    poison self-made weapon..... 
	L75(75), L100 (150), L150 (200), L180(250), L200(300)
	2s-4s-5s-6s-7s	
type 4  herb_e: "������"	depoison	20s

L 200 herb
type 3: herb_f: "��֥","����Ҷ"	random drop    4000/2000/2000 cure poison, heal both value.

Level: requirement for use herb
type : cure,  full, poison, depoison,
field:  kee/gin/sen
effect: amount that it heals, or it poisons,

*/

#include <ansi.h>
#include <condition.h>
inherit "/daemon/condition/generic_condition";
inherit F_CLEAN_UP;

int main(object me, string arg){
        
        int level, herb_level, effect;
        string type, field;
        
        string plant;
        object herb;
        
	if( !arg || sscanf(arg, "with %s", plant)!= 1 ) 
		return	notify_fail("ָ���ʽ��herbheal with <ҩ����>\n");

        if (me->is_busy())
        	return notify_fail("��������æ�ţ�û�����ˡ�\n");
        	
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

	level = me->query_skill("herb",1);
	if(level < 50 )
                return notify_fail("������Ҫ50��ҩ�����ܱ��ҩ�ݵ���;��\n");

	herb = present(plant,me);
	if (!herb)
		return notify_fail("������û��Я��"+plant+"\n");
	
	type = herb->query("type");
	if (type!="cure" && type!="full" && type!="depoison")
		return notify_fail(herb->name()+"�����������ˡ�\n");
	           
        herb_level = herb->query("level");
        if (level < herb_level )
        	return notify_fail("��Դ���ҩ�ݵ������в��˽⣬�޷����������ˡ�\n");
        
        if(me->query("force")<200)
        	return notify_fail("����ҩ����Ҫ200��������\n");
        me->add("force", -200);
        me->force_status_msg("force");
                        
        write( HIG "��ȡ��"+ herb->name() + HIG"���ڿ��н��ã�ȫ����ɣ���������ʼ�������ھ����л���������\n" NOR);
        message("vision", HIG + me->name() + "����������ҩ���ķ����ˣ�ͷ��ð�����ư�����
���ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n"NOR,environment(me), me);
	
	field = herb->query("field");
	if (type == "cure")
	{
		switch (field) {
			case "kee": 	effect = herb->query("effect");
					me->receive_curing("kee", effect);
					tell_object(me,"�����Ѫ������"+effect+"�㡣\n");
					break;
			case "sen":	
			case "gin": 	effect = herb->query("effect");
					me->receive_curing("gin",effect);
					me->receive_curing("sen",effect);
					tell_object(me,"��ľ���������������"+effect+"�㡣\n");
					break;
			default:	tell_object(me,"����㿴����仰���뱨����ʦ��\n");
		}
	}
	if (type == "full")
	{
		switch (field) {
			case "kee": 	effect = herb->query("effect");
					me->receive_fulling("kee", effect);
					tell_object(me,"�����Ѫ�ظ���"+effect+"�㡣\n");
					break;
			case "sen":	
			case "gin": 	effect = herb->query("effect");
					me->receive_fulling("gin",effect);
					me->receive_fulling("sen",effect);
					tell_object(me,"��ľ���������ظ���"+effect+"�㡣\n");
					break;
			default:	tell_object(me,"����㿴����仰���뱨����ʦ��\n");
		}
	}
	if (field == "depoison")
		me->clear_condition();		
	if (field == "depoisonx")
		me->clear_condition_type(LOW_POISON);	        

        herb->add_amount(-1);
        me->start_busy(2);
        return 1;
}
 
int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	herbheal with <ҩ����> [0m
[0;1;37m����������������������������������������������������������������[0m   

����ֵ��ӵ�ר��������ҩ��Ѭ���˿ڣ�Ϊ����������ʥ����
��������Ҫ50��ҩ����

��ͬ��ҩ���в�ͬ��ҩЧ��ҩ��Խ�ߣ���ҩ�ݵ��˽��Խ��̡�
ҩ���ڿ���ֺͷ��ƳǶ��г��ۣ����ã������ָ��쿴
�书Ч��

[0;1;37m����������������������������������������������������������������[0m   
 
HELP
    );
    return 1;
}
 
 