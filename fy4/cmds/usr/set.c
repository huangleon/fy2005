
// set.c

#define MAX_ENV_VARS    20
#include <ansi.h> 
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
    mixed data;
    mapping env;

    if (arg) arg = replace_string(arg, "/", "");
    wiz_only = ({"invisibility", "immortal"});

    if( me != this_player(1) ) return 0;

    env = me->query("env");

    if( !arg || arg=="" ) {
	write("��Ŀǰ�趨�Ļ��������У�\n");
	if( !mapp(env) || !sizeof(env) )
	    write("\tû���趨�κλ���������\n");
	else {
	    terms = keys(env);
	    for(i=0; i<sizeof(terms); i++)
		printf("%-20s  %O\n", terms[i], env[terms[i]]);
	}
	return 1;
    }

    if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
    }

    //      if(term == "wimpy") return notify_fail("����WIMPY���ָ�\n"); 

    if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
		    return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
		sscanf(data, "%d", data);
		if(!wiz_level(me) && (member_array(term, wiz_only) != -1))
		    return notify_fail("ֻ����ʦ����ʹ������趨��\n");
		    
		if (term=="msg_mout" || term=="msg_min"){
		    if (!stringp(data)) return 0;
		    data = replace_string(data, "$BLK$", BLK);
		    data = replace_string(data, "$RED$", RED);
		    data = replace_string(data, "$GRN$", GRN);
		    data = replace_string(data, "$YEL$", YEL);
		    data = replace_string(data, "$BLU$", BLU);
		    data = replace_string(data, "$MAG$", MAG);
		    data = replace_string(data, "$CYN$", CYN);
		    data = replace_string(data, "$WHT$", WHT);
		    data = replace_string(data, "$HIR$", HIR);
		    data = replace_string(data, "$HIG$", HIG);
		    data = replace_string(data, "$HIY$", HIY);
		    data = replace_string(data, "$HIB$", HIB);
		    data = replace_string(data, "$HIM$", HIM);
		    data = replace_string(data, "$HIC$", HIC);
		    data = replace_string(data, "$HIW$", HIW);
		    data = replace_string(data, "$NOR$", NOR);
		    data+= NOR;
		}
		if (term && data)			
		if (term == "savemyass"){
			if (!stringp(data))	
				return notify_fail("savemyass ����ֻ�ܸ����������û�����塣\n");
			if (strsrch(data,"quit")!=-1)
				return notify_fail("����ս���в����˳����˲���û�����塣\n");
		}
		
		if(term == "wimpy") //return notify_fail("����WIMPY���ָ�\n"); 
		    if( !intp(data) || data <0 || data >99  )
			return notify_fail("WIMPY��Ĳ���������0-99�ڵ�ĳһ��ֵ��\n");
		
		if (term == "e_money" && !REWARD_D->check_m_success(me,"�ĺ���"))
			return notify_fail("�㻹�������ĺ��𿨣��޷����ܸ���ҵ��\n");
		
		if (term == "target" && me->query_temp("timer/lost_target")+ 20 > time())
			return notify_fail("������һƬ���ң���ʱ�޷���ȷ������Ŀ�ꡣ\n");
			
		me->set("env/" + term, data);
		printf("�趨����������%s = %O\n", term, data);
		return 1;
    }
    return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : set ������ [����ֵ][0m
[0;1;37m����������������������������������������������������������������[0m
������� set ָ���趨һЩ���õĻ�����������Щ����Ҳ���������
���ﱻ��������������в���Ҫ�Ļ��������������� unset ɾ����
��ϸ��ʹ�÷����뿴 help set �� help unset��

������Ŀǰ���õĻ���������

brief		<�κη����ֵ>	�ƶ�ʱֻ�����ڵؼ�̵����ƣ����
				������·�ٶȲ��Ǻܿ죬�����Ƕ�����
				�Ѿ�ʮ����Ϥ���������� brief�Լ�
				����·������
brief2				�ƶ�ʱֻ�����ڵؼ�̵����ƺ��˺��
brief3				�ƶ�ʱֻ�����ڵؼ�̵����ƺ����Ｐ���ڡ�
				
wimpy		<�ٷֱ�>	�����ľ�����������ٷֱ�ʱ�ͻ��Զ�ִ
				��savemyass��ָ����������savemyass
savemyass	<�κ�ָ��>	û�����ã����Զ����㳢�����뵱ǰλ�á�
				
no_tell		<id/all>	ʹ��ң�id����������ң�all�����޷�
				����˵����

no_give         <1 �� 0>	�����1�����������κ�������������ҵ���
				����Ʒ��ȱʡֵΪ0��				
				
revive          <1 ���� 0>      �����1�����˿�������ʶ��ͨ�Ȱ���
				�㸴������0���ܡ�ȱʡ����0��
				ÿ�θ�����㡣
	
equip_msg 	<1��2 ���� 3>	��ָ���Ŀ����Ϊ�˼���Ƶ���Ĵ���
				��жˢ���������Ϊ�����㽫��������
				��װ����ȥ������װ������Ϣ�������
				�����㽫����������װ����ȥ������װ
				������Ϣ�������3����������������
				Ϊ��ʡϵͳ��Դ�����˵�½ʱ�Զ���Ϊ2��
							
savemymoney     <1 �� 0>	�����1��ɱ�콾�Ľ�����ֱ�Ӵ������
				�����˺š�	

ability				��Quest�Ľ���תΪ������

e_money		<1 �� 0>	�����1��������ֱ�Ӵ�����ת�ˣ��ù���
				ֻ�����ĺ��𿨼����ʹ�á�

target		<id>		�趨��������

dmg_msg		<1 �� 0>	�����1��ϵͳ�����һϵ��״̬��Ϣ

no_cbm		<1 �� 0>	�������д���Ϣ

no_others_cbm   <1 �� 0>	�������˴���Ϣ

[0;1;37m����������������������������������������������������������������[0m
HELP
		);
	return 1;
}
