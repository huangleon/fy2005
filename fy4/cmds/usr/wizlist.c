// wizlist.c
//	--- Credit goes to SNOWMAN@SJ, modified by Silencer@FY4

#include <ansi.h>

inherit F_CLEAN_UP;

mapping hoodname=([
	"(admin)" :  	"��"HIW" ϵ��ͳ "NOR"��",
	"(arch)" : 	    "��"HIR" �ܡ��� "NOR"��",
	"(wizard)" : 	"��"HIG" ������ "NOR"��",
	"(apprentice)": "��"HIY" ѧ  ͽ "NOR"��",
	"(immortal)" :  "��"HIM" �ˡ��� "NOR"��"
]);
int level(mixed, mixed);
int imm(string wizid);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int i, j;

        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
 //	    if (!wiz_level(me)) list = filter_array(list, (: imm :));
        str = sprintf("\n%-30s\n",
        	WHT"��"+MUD_NAME+"Ŀǰ����" + sizeof(list) + "λ��ʦ��"NOR);
		str = replace_string(str, "  ", "��");
        i = sizeof(list);
        while(i--) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if( j ){
                        	while(j > 6) j -= 6;
                        	j = 6 - j;
                        	if( j > 0){
                        		while(j--) str += "         ";
					str += "��";
                        	}
                        	else str += "��";
                        }
                        str += sprintf("\n��%-12s��"NOR, hoodname[hood]);
                        j = 0;
                }

                j++;
                if( j > 6 && j%6==1 )
                	str += "��\n��\t\t";
		str += sprintf("%-9s", capitalize(list[i]));
        }

        if( j ){
                while(j > 6) j = j - 6;
                j = 6 - j;
                if( j > 0) {
                	while(j--) str += "         ";
			str += "��";
                }

                else str += "��";
        }
        
        write(str+"\n");
        
        if (wiz_level(me))
		write("
===================================================================
���ƹ�����ֹ���

"WHT"1��IMMORTAL ����"NOR"
IMMORTAL��������ң�����ʽ��ʦ���޷�������ʦƵ�������ܴ���Ķ�����Ϸ
������йص���������ݡ����ſ�վʱ����ӳ���������Ա�����ܶ�ʮ��Сʱ
���ߣ���Ȩ�޿��Խ���һЩ�����ε����ܳ������ߡ���Ϥ��Ϸ�������ң���
��Ҫ�����ǰ�����ң���Ծ���գ����һЩ���⵷�������⡣
Ŀǰ���Դ��������: edemote, nulock

"WHT"2��WIZARD ������Ա"NOR"
���в�����ǰվ��ķ��ƹ�������Ա������ҪĿ�����ڹ۲��˽���Ϸ������
����Ϊ��һ������������׼����������Ϊ���ϵͳ���У�Ѱ�ң£գǣ���Ȩ��
�޷��޸Ļ�鿴������ݡ�
���Դ����Ӱ���������: ban,exec,nuke,summon
full(����), get(��NPC)��halt(����)��goto�����ڲ���,update(���)

"WHT"3��ARCH ������Ա"NOR"
��ǰվ��Ĺ�����Ա��������Ϊ����ά��վ�㣬�������ì�ܣ��������󣨿�
�޸ĳ�ϵͳ��¼������ݣ�

"WHT"4��ADMIN ϵͳ��Ա"NOR"
���Σ�Э�����ƹ�����������ṩ��ǰվ���Ӳ��֧��
===================================================================
\n");        
        return 1;
}

int imm(string wizid)
{
	return wiz_level(wizid) == 4;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 > ob2?-1:1;
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	wizlist[0m
[0;1;37m����������������������������������������������������������������[0m   

��; : �г�����Ϸվ��������ʦ������

[0;1;37m����������������������������������������������������������������[0m 
HELP
     );
     return 1;
}
