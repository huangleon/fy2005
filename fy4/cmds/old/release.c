// release.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string martial, skill;
	int result;
        
	seteuid(getuid());
	if( me->is_busy() )
		return notify_fail("������һ��������û����ɣ�����ʩ���⹦���� \n");

	if( !arg ) return notify_fail("��Ҫ���⹦��ʲ�᣿\n");

	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
		if( martial != "herb") return notify_fail("�㲻�����������⹦��\n");
	}
	if( stringp(skill = me->query_skill_mapped(martial)) ) {
        	if( SKILL_D(skill)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			return 1;
		}
	return 0;
	}
	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}