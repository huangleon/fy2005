
#include <skill.h>
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int research_limit(object me, string skill)
{
	string myclass;
	int nlimit;

	if( skill == "shortsong-blade" || skill == "diesword") {
		nlimit = 260;
	} else if( skill == "chillblade" ) {
		nlimit = 240;
	} else {
		myclass = me->query("class");
		me->set("class", SKILL_D(skill)->skill_class());
		nlimit = 450 * 100 / SKILL_D(skill)->effective_level(me);
		nlimit = (nlimit / 5 + 1) * 5;
		if( myclass ) {
			me->set("class", myclass);
		} else {
			me->delete("class");
		}
	}
	return (nlimit >= 400 ? 400 : nlimit);
}

int main(object me, string arg)
{
	string skill, check;
	int nlimit;
	int my_skill_level;
	int pot, amount;

	if( me->is_fighting() ) {
		return notify_fail("��ս���и��о���\n");
	}

	if ( !arg ) {
		return notify_fail("ָ���ʽ: research <����> with <Ǳ�ܵ���>\n");
	}

	if( sscanf(arg, "%s with %d", skill, pot) != 2 ) {
		if( sscanf(arg, "%s with %s", skill, check) == 2 ) {
			if ( check == "limit" ) {
				my_skill_level = (int)me->query_skill(skill, 1);
				if( !my_skill_level ) {
        			return notify_fail("��Դ����һ����֪����θ��о���\n");
				}
    			nlimit = research_limit(me, skill);
				tell_object( me, "������ܹ����е�����ߵȼ�Ϊ"+ nlimit +"��\n");
				return 1;
				}
		}
		return notify_fail("ָ���ʽ: research <����> with <Ǳ�ܵ���>\n");
	}

	my_skill_level = (int)me->query_skill(skill, 1);
	if( !my_skill_level ) {
		return notify_fail("��Դ����һ����֪����θ��о���\n");
	}

	if( !SKILL_D(skill)->valid_learn(me) ) {
		return 0;
	}

	nlimit = research_limit(me, skill);
	if( my_skill_level >= nlimit ) {
		return notify_fail("��Ȼ��������У��������������������Ѿ��޷���һ�����������ˡ�\n");
	}
	if( pot < 100 ) {
		 return notify_fail("���Ǳ�ܲ����������о�����������100�㣩\n");
	}
	if( pot > 10000 ) {
		return notify_fail("Ϊ��ֹ�����ÿ�������о���Ǳ�ܲ��ܳ��������������㡣\n");
	}
	if( pot > (int)me->query("potential") - (int)me->query("learned_points") ) {
		 return notify_fail("���Ǳ�ܵ㲻����\n");
	}

	if( me->query_int() <= 40 ) {
		amount = (400 + 30 * me->query_int()) * 2 * pot;
	} else {
		amount = to_int((pow(to_float(me->query_int()*10), 0.03) * 871 - 950) * 173 / 5 * pot);
	}

	if( me->query("national") == "����" ) {	
		amount = amount + amount/20;		// ��������
	}
	amount = amount / SKILL_D(skill)->skill_difficulty();

	//	����ʵ���Ͼ���ֱ��ѧϰ����ܵ�Ч�ʣ������о���˵��/5
	amount = amount / 5;	            	

	write("���"+SKILL_D(skill)->name()+"����һ�����׵��о�����+" +amount +"��\n");
	me->add("learned_points", pot);
	me->add("annie/skill_cost/"+skill, pot);
	me->research_skill(skill, amount);
	return 1;
}
            	
            	
int help(object me)
{
	write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	research <����> with <Ǳ�ܵ���>[0m
[0;1;37m����������������������������������������������������������������[0m   

�����й������ֻ�ȡ���ܵ�;����	���飨study��
				ѧϰ��learn��
				[1;31m���У�research��[0m
				��ϰ��practice��

����ɳ���һ���̶ȣ��ᷢ���Լ��Ѿ�ѧ��������ʦ���ܴ��ڵļ��ܣ�
��Ȼ����Ȼ���Ա������أ�Ѱ���µ�ʦ�������书�ؼ������������㹻
�Ķ�����ѧ������һ���棬��Ҳ���������Լ��Ĳ�������������ѧ���
�����һ�����С�������һ����������ͷ�Ծ�Ĺ��̣��Ѷ�Ҫ����ʦ��
ѧҪ��ö࣬����Ψ������������ܳ�Խǰ�ˣ���Ϊһ����ʦ��

��һָ��������ָ����Ǳ�ܶ�ĳ�����������о���
һ����˵���о����Ѷ���ͬ����ʦ���Ƕ�ѧϰ�����5����
���ѵ��ǣ�������Ҫ�����ĵ�����ѧϰ��������

������
������������ (diesword)                  - ��ͨƤë  22/  530
�������ʦ��ѧ����һ��Ǳ����������Ϊ 23����
��������Լ����У���Ҫ��Ϊ
������������ (diesword)                  - ��ͨƤë  22/  1060
���������23����

���е�Ч��������������أ�
��1�����ǣ�Խ�������ˣ���ͬ����Ǳ�����򵽵ļ��ܾͶࡣ
��2���������ࣺ��ͬ���书�����ѶȲ�ͬ�������׵��Ǵ�����Ĺ���
��3���������ԣ����������Ч�ʱȽϸߡ�

���еľ��ޣ��������֮ʱ������ļ��ܴﵽһ������ʱ��
�����ܵȼ�xϵ��>= 450)
����������Ե���⿿���˵����о��޷���һ������ˡ�
ʹ������ Research <����> with limit ���Բ鿴����ӵ�м��ܿɴﵽ
�����ȼ���

[0;1;37m����������������������������������������������������������������[0m   
HELP
	);
	return 1;
}

