// TIE@FY3
//	��nickname��describe�����ָ�� --- Silencer@fy4

#include <ansi.h>

inherit F_CLEAN_UP;

int do_nickname(object me, string arg);
int do_describe(object me, string arg);

int main(object me, string arg)
{
	object obj;
	string id, verb,replace;
	string tmp;
	if( !arg ) 
		return notify_fail("ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>\n");
	
	if( sscanf(arg, "%s %s %s", id, verb, replace)!=3 )
		return notify_fail("ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>\n");
	
	if (id == "self") {
		if (verb == "nickname")	{
			if (do_nickname( me, replace))
				write("�ı�ɹ���\n");
			return 1;
		}
		if (verb == "description")	{
			if (do_describe( me, replace))
				write("�ı�ɹ���\n");
			return 1;
		}
		return notify_fail("ָ���ʽ : alter self <nickname �� description> <�ı������>\n");
	}
	
	if (me->query_temp("timer/big_cmd")+1 > time())
		return notify_fail("��������ȽϺķ�ϵͳ��Դ��ÿһ�����ִ��һ�Ρ�\n");
	else
		me->set_temp("timer/big_cmd",time());
	
	if( !objectp(obj = present(id, me)) )
		return notify_fail("������û������������\n");
	if(obj->query("owner") != me->query("id"))
		return notify_fail("��ֻ�ܸı�������Ʒ�ϵ�������Ϣ��\n");
	switch(verb) {
		case "desc":
			if(!CHINESE_D->check_chinese(replace)) return notify_fail("�������������ġ�\n");
			obj->set("long",replace+"\n");
			break;
		case "wield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
			return notify_fail("�������뺬��$N��$n��\n");
			tmp = replace_string(replace,"$N","");
			tmp = replace_string(tmp,"$n", "");
			if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");		
			obj->set("wield_msg",replace+"\n");
			break;
		case "unwield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("�������뺬��$N��$n��\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");
                        obj->set("unwield_msg",replace+"\n");
                        break;
		case "wear_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("�������뺬��$N��$n��\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");
                        obj->set("wear_msg",replace+"\n");
                        break;
		case "remove_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("�������뺬��$N��$n��\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("�������������ġ�\n");
                        obj->set("unequip_msg",replace+"\n");
                        break;
		default: 
			return notify_fail("ָ���ʽ : alter <���ĵĶ���> <���ĵĿ���> <�ı������>\n");
		
	}
	obj->save();
	write("�ı�ɹ���\n");
	me->add("sen",-10);
	return 1;
}


int do_nickname(object me, string arg)
{
	if( !arg ) {
		write("ָ���ʽ : alter self nickname <����>\n");
		return 0;
	}
		
	if( strlen(arg) > 40 ) {
		write("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
		return 0;
	}

	if (arg=="none") {
		me->delete("nickname");
		return notify_fail("��ȡ�����Լ��Ĵºš�\n");
	}

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
//	write("Ok.\n");
	return 1;
}

int do_describe(object me, string arg)
{
	string *txt;

	if( !arg ) {
		write("ָ���ʽ : alter self description <����>\n");
		return 0;
	}
	
	if( arg=="none")
	{
		me->delete("long");
		write("����ɾ����ϡ�\n");
		return 1;
	}
	
	if (sizeof(arg)>140)	{
		write("����Լ�������̫���ˣ��������140����֮�ڡ�\n");
		return 0;
	}
	
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 ) {
		write("�뽫�����Լ������������ڰ������ڡ�\n");
		return 0;
	}
	arg = implode(txt, "$NOR$\n") + "\n";

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("long", arg + NOR);
//	write("Ok.\n");
	return 1;
}


int help (object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	alter <���ĵĶ���> <���ĵĿ���> <�ı������>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ���������汾��alter��nick��describe���ۺϣ�

<һ>
���Ҫ�ĵ����Լ��Ĵºţ�	alter self nickname 	<����>
���Ҫ�ĵ��Ǳ��˿��Լ�ʱ��������alter self description 	<����>
�������ȥ���Լ��Ĵº�/����������ʹ�� 
alter self nickname none  ��   alter self description none	

�����ϣ���ڴº�/������
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

$BLK$ - ��ɫ		$NOR$ - �ָ�������ɫ
$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ
 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

<��>
���Ҫ�ĵ���������Ʒ�ϵ���Ϣ��
	alter <���ĵĶ���> <���ĵĿ���> <�ı������>			
	
	���ԸĵĿ��������
		desc  		��Ʒ������
		wield_msg 	װ������������
		unwield_msg	���±���������
		wear_msg	���Ͽ��׵�����
		remove_msg	���¿��׵�����

��������һ��Ѫ��(redsword)��
	alter redsword wield_msg ֻ�����һ�֣�$N�Ѱ�$n��������	

	�Ժ�ÿ����װ��redsword(wield redsword)����Ҷ��ῴ����
	��ֻ�����һ�֣������Ѱ�Ѫ���������У�	

Ҫע����ǣ���Ҫ��������Ʒ�����ֽ�����self����

[0;1;37m����������������������������������������������������������������[0m   
HELP

);
        return 1;
}
