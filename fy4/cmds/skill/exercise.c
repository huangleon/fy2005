// exe ������ϰ�� ������������������� 
//	��������exercise, meditate, respirate ���ۺϣ�
//	Ŀ���Ǽ�����Ҽ��䷱��������----- Silencer @ fy4


#include <skill.h>
inherit F_CLEAN_UP;

string *add = ({ "qi", "jing", "shen" });
mapping *type = ({
	([      "add":                	"force",
                "add_c":		"����",
                "cost":           	"kee",
                "cost_c":            	"��Ѫ",
                "skill":		"force",
                "u_msg":		"�������������ù���һ����Ϣ��ʼ������������\n",
                "l_msg":		"���ǵ����й���ϣ�ֻ����ȫ���顣\n",
                "f_msg":		"�������Ϣ�鲼ȫ����ʱȴû�й��������ļ����ƺ�������Ϊ�Ѿ�������ƿ����\n",
        ]),
	([      "add":                	"atman",
                "add_c":		"����",
                "cost":           	"gin",
                "cost_c":            	"����",
                "skill":		"magic",
                "u_msg":		"����ϥ�����������۾���ʼ����˼����\n",
                "l_msg":		"������һ��С��ȴ˯���ˡ�\n",
                "f_msg":		"�����һ��������ת��ͷ�ǵ���Ҫ�ѿ�һ�����ƺ������������Ѿ�������ƿ����\n",
        ]),
        ([      "add":                	"mana",
                "add_c":		"����",
                "cost":           	"sen",
                "cost_c":            	"����",
                "skill":		"spells",
                "u_msg":		"����ϥ����������ڤ˼��һ�����\n",
                "l_msg":		"���ǵ��������۾���ֻ��������һƬ�հס�\n",
                "f_msg":		"���Ȼ��������һƬ���ң��ƺ������������Ѿ�����ƿ����\n",
        ]),
});

int main(object me, string arg)
{
    	int kee_cost=30;
    	int n, amount, gain , i;
    	string add_1, h_cost, h_gain;
    	
    	seteuid(getuid());
        
    	if(environment(me)->query("no_fight"))
        	return notify_fail("�㲻��������������������\n");
               	
    	if( me->is_fighting() )
        	return notify_fail("ս���в����������������߻���ħ��\n");
    	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ���������������\n");
    
    	if (!arg || sscanf(arg, "%s %d", add_1, amount) != 2)
    		return notify_fail("ָ���ʽ��exercise <jing/qi/shen> <��Ŀ> \n");
    	
     	n = member_array(add_1, add);
    	if ( n == -1)
    		return notify_fail("��ʽ��exercise <jing/qi/shen> <��Ŀ> \n");
    	   	   	
    	if (amount < 10)
    		return notify_fail(type[n]["add_c"]+"������������Ҫ�ķ�10��"+ type[n]["cost_c"]+ "��\n");
    		
//	write ("add_1 is "+  type[n]["cost"] + " amount is "+ amount +"\n");
 
		h_cost = type[n]["cost"];
		h_gain = type[n]["add"]; 
 
 		if( me->query(h_cost) < amount )
        	return notify_fail("�����ڵ�"+ type[n]["cost_c"]+ "̫���ˣ��޷�������ϰ��\n");

		if (me->query("death_revive")+ 180 > time())
			return notify_fail("�����ڵ�����״���޷�����������\n");
	
		for (i=0;i<sizeof(type); i++) {
		if (i == n)	continue;
		if ( me->query( type[i]["cost"]) * 100 / me->query ("max_"+ type[i]["cost"]) < 70 )
        		return notify_fail("����������״��̫���ˣ��޷�������������" + 
        			type[i]["cost_c"] + "ֵ������70%���ϣ�\n");
    	}
        	
        	
		write(type[n]["u_msg"]);
        	
 		me->add(h_cost, -amount);
    	me->start_busy(1);

	// (500/10 + 40 )/30 = 3 , (3 + random (3))/ 5= 60% - 120% Ч�� maxium at enable= 500, att = 40��
    	
    	gain = me->query_skill(type[n]["skill"]) /10;
    	switch (h_cost) {
    		case "kee":	gain =  amount * (gain + me->query_con()) / 30; break;
    		case "sen":	gain =  amount * (gain + me->query_spi()) / 30; break;
    		case "gin":	gain =  amount * (gain + me->query_int()) / 30; break;
    		default:	write(" �㷢����һ�����棬������������ʦ��\n"); return 1;
    	}
    		
    	gain = (gain + random(gain))/5;

    	if( gain < 1 ) {
        	write(type[n]["l_msg"]);
        	return 1;
    	}

//	write ("amount is "+ amount + " gain is "+ gain + "\n");
    	me->add( h_gain, gain );

		if( me->query(h_gain) > me->query("max_" + h_gain) * 2) {
        	if( me->query("max_" + h_gain) >= ( me->query_skill( type[n]["skill"], 1) + 
             						me->query_skill(type[n]["skill"])/5 ) * 5 ) {       		
            		write(type[n]["f_msg"]);
			me->set(h_gain, 2 * me->query("max_" + h_gain));	
		} else {
            		write("���"+ type[n]["add_c"] + "��ǿ�ˣ�\n");
            		me->add("max_" + h_gain, 1);
            		me->set(h_gain, me->query("max_"+h_gain ));
        	}
        }
        me->status_msg("all");
        me->force_status_msg("all");
    	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	exercise <jing|qi|shen> <����>[0m
[0;1;37m����������������������������������������������������������������[0m
����2005�е���������ָ������ڰ汾�м���Ľ�����ԭ����exercise��
meditate��respirate�����ۺ�Ϊͬһ��������������ּ��䡣

����ָ�������Ĳ�ͬ���������������֣��ֱ����������������������

exercise jing <����> 	�������У����á�������������������
			�����项�ķ�������ľ���ת���[0;1;31m����[0m��

exercise qi <����> 	�����������������ڵ����ڸ�������������
			����ѵ�����弡���������������������
			������[0;1;31m����[0m����ʽ����������������
			
exercise shen <����>	����ڤ˼��������ľ�������Ч�ؼ�����
			�۳��ܹ�����ʩչ��������������������
			�Լ���[0;1;31m����[0m��


�����õ����������ֵ == �����ڹ��ȼ�*5 + ��ǰ����Ч�ڹ��ȼ�
����:���ڹ��ķ� (force)                      �� -��ɲ�  200
���� ���ڹ� (force)          �� ���繦           ��Ч�ȼ���295 
�������ֵ = 200*5 + 295 = 1295

ƽ��ת��Ч�ʣ� ����Ч�ڹ��ȼ������������ʣ���������

�����������ļ�����������ȫ��ͬ��

���ָ�
	�ָ�������	������������
	�ָ�����	��������������
	�ָ�������	��������������
[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
 
