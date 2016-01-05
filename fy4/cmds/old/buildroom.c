inherit F_CLEAN_UP;
int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, int flag,string dir, string text);
#define SCORE_COST 5000
#define GOLD_COST  1000
#define MIN_EXP	100000
int main(object me, string arg)
{
	int flag;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %d",dir,stitle,flag) != 3)
		return notify_fail("ָ���ʽ����buildroom north �ҵ�С�� 0\n");
	if((int)me->query("score") < SCORE_COST)
		return notify_fail("������۵㲻��"+chinese_number(SCORE_COST)+	"�㡣\n");
        if((int)me->query("combat_exp") < MIN_EXP)
        	return notify_fail("���ʵս���鲻��������15����\n");
	gold = present("gold_money",me);
		if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < GOLD_COST)
        	return notify_fail("������û��"+chinese_number(GOLD_COST)+"�����ӡ�\n");
	if((int)me->query("created_room") > 3)
		return notify_fail("�㲻���ٽ����ˣ�\n");
        
        env = environment(me);
        if(!env->query("owner") && (string)env->query("owner") != "public" 
	&& (string)env->query("owner") != (string) me->query("id"))
        	return notify_fail("�㲻�����⽨����\n");
	if(check_legal_name(stitle))
		 me->edit( (: enter_desc , me,gold, stitle, flag, dir :) );
	return 1;
	
}
void enter_desc(object me,object gold, string s_title, int flag,string dir,string text)
{
string *direc= ({"north", "south", "east", "west", "northup", 
"southup", "eastup", "westup", "northdown",
"southdown", "eastdown", "westdown", "northeast", 
"northwest", "southeast", "southwest", "up", "down"});
	int i;
	int okey=0;
	object env;
	if(!check_legal_long(text)) return;
        for (i = 0; i < sizeof(direc); i++)
	if(direc[i] == dir) {okey=1; break;}
	if(okey)	
	{
	env = environment(me);
	if(env->query("exits/"+dir))
		{
		tell_object(me,"��������Ѿ��з����ˣ�\n");
		return;
		}
// I think by now, we should checked all conditions,
// deduct the cost and go build it!
		gold->add_amount(-GOLD_COST);
		me->add("score",-SCORE_COST);
		BR_D->buildroom(me,flag,s_title,text,dir);
	}
	else
	{
		tell_object(me,"��Ҫ���ĸ����򽨣�\n");
		return;
	}
}

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 120) || (strlen(name) > 600 ) ) {
                write("�Բ�������������������ʮ�����ٸ������֡�\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("�Բ����������������ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ����������������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int help (object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	build <ѶϢ>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ������ҽ���һ�������Լ��ķ��ݡ�

����һ�����ݵĻ���Ϊ5000���ۡ�1000���ƽ�ÿ����������Խ�
���������ӡ�

������ڷ����дﵽһ���ĵ�λ��ӵ���㹻�ĲƸ����������Ϳ�����
���Ƴ��Ա���ɽ���н��������Լ��Ŀռ䡣�ڶ���һ����Ժ�������
��һ�����������Լ������ɻ��ᡣÿ���ռ�����в�ͬ�����ʣ�
�������Լ���˽��סլ��ֻ������Լ����Խ��룩��Ҳ�����ǰ��ɵ�
˽�أ�ֻ��ͬ�ɵ��˿��Խ��룩�������ǽ�ֹ��ɱ�ĵط���Ҳ������
�޷�����ĵضΡ����佨�����֮�����е����ʣ���������������
�ı䣬���Դ�����趨�����ʱ��һ��Ҫ��ӿ��ǣ�����ѡ��

���췿�����ϸ�������£�

buildroom <����> <��������> <��־>

����	�����Ƕ������ڵ�λ�ö��ԣ����������north������˵��Ҫ
	�������Ա��ķ��򽨷���
�������ƣ������������ļ��������
��־��	�������ķ��������ȫ���ɱ�־������������ѡ��ı�־�У�
	1�������ڴ˴浵�����´�����ʱ�ڴ˴���ʼ��
	2��ֻ������ҽ���Ŀռ䣨���ɴ�������
	4������ս���Ŀռ䣨���ɴ�������
	8�������з�����ħ���Ŀռ䣨���ɴ�������
	16������Ŀռ䣨�����˶����Խ��룬���û�����16����
		����Ҳ��������ڣ���
	512��ֻ�����Լ�����Ŀռ䡣
	1024��ֻ����ͬ�ŵ��������Ŀռ䡣
	2048���������루invite�����˽���Ŀռ䡣
	
buildroom north Сľ�� 2
�ͻ����Ա��ĵط�����һ��С����Ϊ��Сľ�ݡ���ľ�ݵ�������ֻ��
��������ǽ��롣

buildroom southdown ���䳡 1040
�ͻ����ϱߵʹ�����һ������ռ���Ϊ�����䳡�����˳�����������
�⣨16����ֻ��ͬ�ŵ��ˣ�1024���ſ��Խ��루1024+16=1040����

buildroom eastup �ƽ��� 525
�ͻ��ڶ����ߴ�����һ��������Ϊ���ƽ��ݡ������ݵ��������´�
���ڴ����߽��루1�������ɴ�ɱ��4��������ʩչħ����8������ֻ
�����Լ����루512����1��4��8��512��525����

����������Ͻ�������һ��ķ���ʱ���б�Ҫ��setowner���ָ���
�����������ʱ��Ϊ���ˡ�

[0;1;37m����������������������������������������������������������������[0m   
HELP
	);
	return 1;
}
