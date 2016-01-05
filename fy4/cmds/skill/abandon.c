// abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;
void abandon_skill(string confirm, object me, string skill);
int zero_skill(object me, string arg);
mapping valid_types = ([
//		"array":        "��",
		"animal-training":  "ѵ����",
		"axe":    	"����",
		"blade":        "����",
		"dagger":       "�̱���",
		"dodge":        "������",
		"force":        "�ڹ�",
		"fork":         "�淨",
		"hammer":       "����",
		"iron-cloth": 	"Ӳ��",
		"literate": 	"��д",
		"magic":        "����",
		"move":         "�Ṧ",
		"parry":        "�м�",
		"perception":   "������",
		"scratching":   "��֮��",
		"cursism" :	"��ͷ��",
		"spells":       "����",
		"staff":        "�ȷ�",
		"stealing":     "������",
		"sword":        "����",
		"throwing":     "����",
		"unarmed":      "ȭ��",
		"whip":     	"�޷�",
		"herb":		"ҩ��",
		"spear":        "ǹ��",
		"musket":				"��ǹ",
]);



int main(object me, string arg)
{
	string err;
	
	if( !arg || arg=="" ) return notify_fail("��Ҫ������һ��ܣ�\n");

	if(!find_object(SKILL_D(arg)) && file_size(SKILL_D(arg)+".c")<0) {
		return notify_fail("��" + arg + "���������ּ�����\n");	
	}
	/*if(!load_object(SKILL_D(arg)+".c")) 
		return notify_fail("��" + arg + "���������ּ�����\n");
	*/	
    seteuid(getuid());
    err = catch( call_other(SKILL_D(arg)+".c", "???") );
    if (err)
       printf( "��������\n%s\n", err );
	
	if( !me->query_skill(arg,1) && !zero_skill(me,arg))
		return notify_fail("�㲢û��ѧ������ܡ�\n");
		
	if (arg == "magic" || arg == "force" || arg == "spells")
		return notify_fail("�����������Ӱ����ľ�������ֵ���޷�������\n");
		
	write(HIY"\n����������ָ������ܴ��������������ɾ����������Ժ�Ҫ����������㿪
ʼ����������ؿ��������\n\n"NOR);
	
	if (me->query("annie/skill_cost/"+arg)>0) {
		write(HIY"���Ѿ������ż����ϻ�����"+me->query("annie/skill_cost/"+arg)+"��Ǳ�ܣ�������ʹ�ã�������ķ�ʽ�ջ���ЩǱ
��ѧ������������������ķ�ʽ��ο�����𡡣�������ĵڣ���������
��ָ���жϡ�\n\n"NOR);
		return 1;
	}
	
	write("��ȷ����������ѧϰ��"HIR + SKILL_D(arg)->name() + NOR"�ݣ��Ƿ�Ҫ������(yes/no)\n");
	input_to( (: abandon_skill :), me, arg);
	return 1;
}

void abandon_skill(string confirm, object me, string skill) 
{
	if (! (confirm == "yes" || confirm == "YES")) 
		write("�����һ���亹�����գ�\n");
	else    {
        	if(me->query_skill(skill,1)>50)
        	log_file("skills/ABANDON",
        	  sprintf("%s(%s)��%s������%d��%s��\n",
        	  me->name(1),geteuid(me),ctime(time()),me->query_skill(skill,1),skill));
		me->delete_skill(skill);
		me->reset_action();
		write("�������������ѧϰ" + SKILL_D(skill)->name() + "��\n");
	}
}


int zero_skill(object me, string arg) {
	mapping learned_skill_points;
	
	learned_skill_points=me->query_learned();
	if (!mapp(learned_skill_points))	return 0;
	if (!learned_skill_points[arg]) return 0;
	return 1;
}


	
	
	

int help()
{
	write(@TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ��abandon <��������>[0m
[0;1;37m����������������������������������������������������������������[0m

����һ������ѧ�ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�����
���������ɾ����������Ժ�Ҫ���������0��ʼ����������ؿ�����
����

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ����
���Ǽ������������ʱ������������ĸ��ֶ�����ս����ѧϰ�������Щ
���ܻ���Ϊ�㾭����ʹ�ö���������ļ����б��У��������ͱ��뻨��
һЩ����ȥ����ס����ѧ����һ�У�Ȼ�����˵����ʸ��в�ͬ�����Ըߵ�
���ܹ�ѧϰ��༼�ܶ���Ϊ��Ŷ��յĲ��ӣ����Խϲ���˾�ֻ��ר���
�ض�����ܣ������ѧ�ļ�������̫�࣬����������ԣ���ᷢ������
��ѧϰ�ٶȽ���ֻѧ���ּ��ܵ�����������Խ�࣬ѧϰЧ����������Խ
���أ��������ξ�����һ��ѧ��ͬʱѡ��̫��ѧ�֣���Ȼ����Ȼ����ƾ��
���˵���־������ȥ�������⽫��໨������౦���ʱ�䡣

ע��ѧϰ�������������ԣ���ʱѧϰЧ�ʽ����͡�
[0;1;37m����������������������������������������������������������������[0m
TEXT
	);
	return 1;
}
