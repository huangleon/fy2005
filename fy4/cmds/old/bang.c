#define SCORE_COST 30000
#define GOLD_COST 2000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
    string c_name,title,stitle;
    string *dir;
    int i;

    seteuid(getuid());
    if(!arg || sscanf(arg,"%s %s %s", c_name, title,stitle) != 3)
        return notify_fail("ָ���ʽ��bang <�������> <�����ƺ�> <���ӳƺ�>\n");
    
    if( mapp(me->query("family")))
        if(me->query("family/privs")==1)
            return notify_fail("��������һ��֮���������ٴ��������ˡ�\n");
        else if(me->query("family/privs")==-1)
            return notify_fail("����һ��֮���������ٴ��������ˡ�\n");
    
    if((int)me->query("score") < SCORE_COST)
        return notify_fail("������۵㲻��"+chinese_number(SCORE_COST)+
                           "�㡣\n");
    if((int) me->query("deposit") < GOLD_COST*100*100)
        return notify_fail("��������û��"+chinese_number(GOLD_COST)+
                           "�����ӡ�\n");
    if(!check_legal_name(c_name) || !check_legal_name(title) ||
       !check_legal_name(stitle))
	return 1;
    dir = get_dir(DATA_DIR+"guild/");
    for(i=0; i<sizeof(dir); i++) 
        if(dir[i] == c_name)
            return notify_fail("���봴���İ��������Ѿ�������ռ���ˣ�\n");	
    if(!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("��Ϸϵͳ�������⣡��֪ͨ������Ա��\n");
    me->delete("family");
    me->create_family(c_name,1,title);
    me->set("class","player");
    me->set("student_title",stitle);
    me->add("score",-SCORE_COST);
    me->add("deposit",-GOLD_COST*10000);
    CHANNEL_D->do_sys_channel("info",sprintf(
        "%s(%s)�����ˡ�%s����",me->name(1),me->query("id"),c_name));
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

