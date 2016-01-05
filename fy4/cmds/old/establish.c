#define SCORE_COST 50000
#define GOLD_COST 2000
#define EXP_LIMIT 5000000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
    string c_name,c_attri;
    string *dir;
    int i;

    seteuid(getuid());
    if(!arg || sscanf(arg,"%s %s", c_name,c_attri) != 2)
        return notify_fail("ָ���ʽ��establish <��֯����> <��֯����(��,а �� ����)> \n");
	if (c_attri != "��" && c_attri != "а" && c_attri != "����")
		return notify_fail("��ֻ�ɴ�(��,а �� ����)ѡһ���������֯�����ԡ�");
	
    
    if( mapp(me->query("organization")))
        if(me->query("organization/privs")==1)
            return notify_fail("��������һ��֮���������ٴ��������ˡ�\n");
        else if(me->query("organization/privs")==-1)
            return notify_fail("����һ��֮���������ٴ��������ˡ�\n");
    
    if((int)me->query("score") < SCORE_COST)
        return notify_fail("������۵㲻��"+chinese_number(SCORE_COST)+
                           "�㡣\n");
	if((int)me->query("combat_exp") < EXP_LIMIT)
        return notify_fail("��ľ���ֵ����"+chinese_number(EXP_LIMIT)+
                           "�㡣\n");

    if((int) me->query("deposit") < GOLD_COST*100*100)
        return notify_fail("��������û��"+chinese_number(GOLD_COST)+
                           "�����ӡ�\n");
    if(!check_legal_name(c_name))
	return 1;
    dir = get_dir(DATA_DIR+"guild/");
    for(i=0; i<sizeof(dir); i++) 
        if(dir[i] == c_name)
            return notify_fail("���봴������֯�����Ѿ�������ռ���ˣ�\n");	
    if(!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("��Ϸϵͳ�������⣡��֪ͨ������Ա��\n");
    me->delete("organization");
    me->create_organization(c_name,1,c_attri);
  //  me->set("student_title",stitle);
    me->add("score",-SCORE_COST);
    me->add("deposit",-GOLD_COST*10000);
    CHANNEL_D->do_sys_channel("info",sprintf(
        "%s(%s)��%s������%s����֯��%s����",me->name(1),me->query("id"),NATURE_D->game_time(),c_attri,c_name));
    return 1;
}
 
int help(object me)
{
    write(@HELP
�����ڷ����г����Լ��İ��ɣ�

ָ���ʽ��bang <�������> <�����ƺ�> <���ӳƺ�>

��ָ�����㴴��һ���µİ�ɣ���̡� 

���磺

bang ѩ���� ���� ����
����ѩ���̣����Լ���ѩ���̽������������ѩ���̽���

bang �߸�ɽ ɽ���� ඿�
�����߸�ɽ�����Լ����߸�ɽɽ��������������߸�ɽ඿�
HELP
    );
    return 1;
}
 
int check_legal_name(string name)
{
    int i;
    i = strlen(name);
    if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
        write("�Բ����������ֱ���������ʮ��������֡�\n");
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

